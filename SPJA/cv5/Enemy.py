import pygame

from Explosion import Explosion
from GameObject import GameObject


class Enemy(GameObject):
    def __init__(self, image, pos, health=100, score=100, speed=100, damage=10):
        super().__init__(image, pos)

        self.health = health
        self.score = score
        self.speed = speed
        self.damage = damage

        self.health_red = health
        self.health_max = health

        self.health_debuff = False

    def update(self, engine, delta):
        if self.health_red > self.health:
            self.health_red -= 30 * delta
        elif self.health_red < self.health:
            self.health_red = self.health

        self.collision_check(engine)

        if self.rect.left < 0:
            self.rect.left = 0
        if self.rect.right > engine.width:
            self.rect.right = engine.width
        pass

        if self.health_debuff:
            self.hit(engine, 50 * delta)

    def hit(self, engine, dmg):
        self.health -= dmg
        if self.health <= 0:
            self.die(engine, False, True)

    def die(self, engine, player_dmg=False, explosion=True):
        if player_dmg:
            engine.player.take_damage(self.damage)
        else:
            engine.player.score += self.score

        if explosion:
            engine.sprites.add(
                Explosion((self.rect.left + self.rect.width / 2 - 32, self.rect.top + self.rect.height / 2 - 32)))
        engine.enemies.remove(self)

    def draw(self, surface):
        surface.blit(self.image, self.rect)
        self.draw_hpbar(surface)

    def draw_hpbar(self, surface):
        # Health bar
        hpbar_size = 48
        pygame.draw.rect(surface, (64, 0, 0),
                         (self.rect.left + self.rect.width / 2 - hpbar_size / 2,
                          self.rect.top - 8, hpbar_size, 4))
        if self.health_red > 0:
            pygame.draw.rect(surface, (255, 0, 0),
                             (self.rect.left + self.rect.width / 2 - hpbar_size / 2,
                              self.rect.top - 8, hpbar_size * self.health_red / self.health_max, 4))
        if self.health > 0:
            pygame.draw.rect(surface, (0, 255, 0),
                             (self.rect.left + self.rect.width / 2 - hpbar_size / 2,
                              self.rect.top - 8, hpbar_size * self.health / self.health_max,
                              4))

    def collision_check(self, engine):
        collide_list = pygame.sprite.spritecollide(self, engine.missiles, True)
        enemies_collide_list = pygame.sprite.spritecollide(self, engine.enemies, False)

        if self.rect.top > engine.height or self.rect.colliderect(engine.player.rect):
            self.die(engine, True, False if self.rect.top > engine.height else True)
        elif len(collide_list) > 0:
            for missile in collide_list:
                self.hit(engine, missile.damage)

        if len(enemies_collide_list) > 0:
            total = len(enemies_collide_list)
            for enemy in enemies_collide_list:
                if enemy is self:
                    total -= 1
                    continue
                enemy.die(engine, False, True)
            if total > 0:
                self.die(engine, False, True)
