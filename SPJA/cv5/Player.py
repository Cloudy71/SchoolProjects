import pygame
from pygame.constants import K_RIGHT, K_LEFT, K_UP, K_DOWN, KEYDOWN, KEYUP, K_SPACE

from Beam import Beam
from Explosion import Explosion
from utils import load_image
from GameObject import GameObject


class Player(GameObject):
    def __init__(self, engine, pos):
        super().__init__(load_image('images/plane.gif'), pos)

        self.image_straight = self.image
        self.image_left = load_image('images/plane_turning_right_1.gif')
        self.image_right = load_image('images/plane_turning_left_1.gif')
        self.image_left_fast = load_image('images/plane_turning_right_2.gif')
        self.image_right_fast = load_image('images/plane_turning_left_2.gif')

        self.image_shield = load_image("images/shield.png")
        self.image_shield = pygame.transform.scale(self.image_shield, (80, 80))
        self.shield_rect = self.image_shield.get_rect()

        self.engine = engine
        self.speed = [0, 0]  # [x, y]
        self.score = 0
        self.health = 100
        self.shield = 0
        self.energy = 100
        self.font = pygame.font.Font(None, 36)
        self.speed_addition_side = 1000
        self.speed_addition_forward = 300
        self.speed_value_side_max = 500
        self.speed_value_side_moving = 150
        self.speed_value_side_moving_fast = 300
        self.speed_value_forward_max = 200
        self.forward_max_y = 240

        self.move_keys = []
        self.shoot_cooldown = 100
        self.shoot_last = pygame.time.get_ticks()
        self.health_red = 100
        self.energy_red = 100

        self.energy_regen = 1
        self.energy_regen_cooldown = 15
        self.energy_regen_shoot_cooldown = 1000
        self.energy_regen_last = 0
        self.energy_price = 10

        self.beams = pygame.sprite.Group()
        self.last_beam = pygame.time.get_ticks()
        self.beam_cooldown = 200
        self.beam_offset = 16
        self.beam_init = 0
        self.beam_tomax = 3000
        self.score_display = 0
        self.score_display_time = 33
        self.score_display_last = 0

    def handle_keys(self, event, delta):
        arrows = (K_RIGHT, K_LEFT, K_UP, K_DOWN)

        if event.type == KEYDOWN:
            if event.key == K_SPACE:
                if pygame.time.get_ticks() >= self.shoot_last + self.shoot_cooldown and self.energy >= self.energy_price:
                    self.engine.spawn_missile()
                    self.shoot_last = pygame.time.get_ticks()
                    self.energy -= self.energy_price

            if event.key not in self.move_keys and event.key in arrows:
                self.move_keys.append(event.key)
        elif event.type == KEYUP:
            if event.key in arrows:
                if event.key in self.move_keys:
                    self.move_keys.remove(event.key)

                if len(self.move_keys) == 0:
                    self.image = self.image_straight

    def stop_moving(self, axis, spd, delta):
        if self.speed[axis] > 0:
            self.speed[axis] -= spd * delta
            if self.speed[axis] < 0:
                self.speed[axis] = 0
        elif self.speed[axis] < 0:
            self.speed[axis] += spd * delta
            if self.speed[axis] > 0:
                self.speed[axis] = 0

    def do_movement(self, delta):
        if K_LEFT in self.move_keys:
            self.speed[0] -= self.speed_addition_side * delta
            if self.speed[0] < -self.speed_value_side_max:
                self.speed[0] = -self.speed_value_side_max

            if -self.speed_value_side_moving_fast < self.speed[0] < -self.speed_value_side_moving:
                self.image = self.image_left
            elif self.speed[0] < -self.speed_value_side_moving_fast:
                self.image = self.image_left_fast
        if K_RIGHT in self.move_keys:
            self.speed[0] += self.speed_addition_side * delta
            if self.speed[0] > self.speed_value_side_max:
                self.speed[0] = self.speed_value_side_max

            if self.speed_value_side_moving < self.speed[0] < self.speed_value_side_moving_fast:
                self.image = self.image_right
            elif self.speed[0] > self.speed_value_side_moving_fast:
                self.image = self.image_right_fast
        if K_UP in self.move_keys and self.energy > 12 * delta:
            max_speed = ((self.engine.height - self.forward_max_y) - (self.engine.height - self.rect.bottom)) / (
                    self.engine.height - self.forward_max_y)

            self.energy -= 12 * delta

            if self.speed[1] > 0:
                self.speed[1] = 0
            self.speed[1] -= self.speed_addition_forward * max_speed * delta
            if self.speed[1] < -(self.speed_value_forward_max * max_speed):
                self.speed[1] = -(self.speed_value_forward_max * max_speed)
        if K_DOWN in self.move_keys:
            self.speed[1] += self.speed_addition_forward * 4 * delta
            if self.speed[1] > self.speed_value_forward_max * 2:
                self.speed[1] = self.speed_value_forward_max * 2

        if -self.speed_value_side_moving <= self.speed[0] <= self.speed_value_side_moving:
            self.image = self.image_straight

    def update(self, engine, delta):
        self.do_movement(delta)
        x, y = self.speed
        rect = self.rect
        self.rect = self.rect.move(x * delta, y * delta)
        if (self.rect.left <= 0 or
                self.rect.right >= engine.screen.get_width() or
                self.rect.top <= 0 or
                self.rect.bottom >= engine.screen.get_height()):
            self.rect = rect
            self.speed = [0, 0]
        self.shield_rect.left = self.rect.left - 40 + self.rect.width / 2
        self.shield_rect.top = self.rect.top - 40 + self.rect.height / 2

        if self.health_red > self.health:
            self.health_red -= 30 * delta
        elif self.health_red < self.health:
            self.health_red = self.health

        if self.energy_red > self.energy:
            self.energy_red -= 50 * delta
        elif self.energy_red < self.energy:
            self.energy_red = self.energy

        if self.energy < 100 and pygame.time.get_ticks() >= self.shoot_last + self.energy_regen_shoot_cooldown and pygame.time.get_ticks() >= self.energy_regen_last + self.energy_regen_cooldown \
                and K_UP not in self.move_keys:
            self.energy += 1
            self.energy_regen_last = pygame.time.get_ticks()

        if K_LEFT not in self.move_keys and K_RIGHT not in self.move_keys:
            self.stop_moving(0, self.speed_addition_side, delta)
        if K_UP not in self.move_keys and K_DOWN not in self.move_keys:
            self.stop_moving(1, self.speed_addition_side, delta)

        self.beams.update(self.engine, delta)

        if K_UP in self.move_keys and self.energy > 12 * delta:
            if self.beam_init == 0:
                self.beam_init = pygame.time.get_ticks()
            beam_speed = (pygame.time.get_ticks() - self.beam_init) / self.beam_tomax
            if beam_speed > 1:
                beam_speed = 1
            max_speed = 0.3 + beam_speed
            offset = self.engine.width / self.beam_offset

            if pygame.time.get_ticks() >= self.last_beam + (self.beam_cooldown / max_speed):
                self.last_beam = pygame.time.get_ticks()
                for i in range(self.beam_offset):
                    bx = i * offset + self.engine.random.randint(0, offset)
                    by = self.engine.random.randint(0, self.engine.height)
                    self.beams.add(Beam(self, (bx, by)))

            for beam in self.beams:
                beam.speed = max_speed * 2000
        else:
            # self.beams.empty()
            self.beam_init = 0
            if self.rect.bottom < self.engine.height - 8:
                self.rect.top += 200 * delta

            pass

        if self.score_display < self.score and pygame.time.get_ticks() >= self.score_display_last + self.score_display_time:
            remaining = self.score - self.score_display
            if remaining > 1000:
                self.score_display += 1234
            elif remaining > 100:
                self.score_display += 123
            elif remaining > 10:
                self.score_display += 12
            else:
                self.score_display += 1

            if self.score_display > self.score:
                self.score_display = self.score

            self.score_display_last = pygame.time.get_ticks()

    def draw(self, surface):
        self.beams.draw(surface)
        if self.health > 0:
            super().draw(surface)
        if self.shield > 0:
            surface.blit(self.image_shield, self.shield_rect)
        self.draw_status(surface)

    def draw_status(self, screen):
        if pygame.font:
            if self.health > 0:
                # draw score
                text = self.font.render('{}'.format(self.score_display), 1,
                                        (255, 0, 0))
                textpos = text.get_rect(centerx=screen.get_width() / 2, top=8)
                screen.blit(text, textpos)
            else:
                text1 = self.font.render("Game Over", 1, (255, 64, 64))
                text2 = self.font.render('Your score: {}'.format(self.score), 1,
                                         (255, 64, 64))
                textpos1 = text1.get_rect(centerx=screen.get_width() / 2, centery=screen.get_height() / 2)
                textpos2 = text2.get_rect(centerx=screen.get_width() / 2, centery=screen.get_height() / 2 + 24)
                screen.blit(text1, textpos1)
                screen.blit(text2, textpos2)

        hpbar_size = 64

        # Health bar
        pygame.draw.rect(screen, (64, 0, 0),
                         (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 8, hpbar_size, 4))
        if self.health_red > 0:
            pygame.draw.rect(screen, (255, 0, 0),
                             (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 8,
                              hpbar_size * self.health_red / 100, 4))
        if self.health > 0:
            pygame.draw.rect(screen, (0, 255, 0),
                             (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 8,
                              hpbar_size * self.health / 100,
                              4))

        if self.shield > 0:
            pygame.draw.rect(screen, (255, 255, 255), (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 8,
                                                       hpbar_size * self.shield / 100, 4))

        # Energy bar
        pygame.draw.rect(screen, (0, 0, 32),
                         (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 4, hpbar_size, 4))

        if self.energy_red > 0:
            pygame.draw.rect(screen, (0, 164, 255),
                             (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 4,
                              hpbar_size * self.energy_red / 100, 4))
        if self.energy > 0:
            pygame.draw.rect(screen, (0, 128, 255),
                             (self.engine.width - hpbar_size - 8, self.engine.height - 8 - 4,
                              hpbar_size * self.energy / 100,
                              4))

    def take_damage(self, amount):

        if self.shield > amount:
            self.shield -= amount
            amount = 0
        else:
            amount -= self.shield
            self.shield = 0

        self.health -= amount

        if self.health <= 0:
            self.engine.sprites.add(
                Explosion((self.rect.left + self.rect.width / 2 - 32, self.rect.top + self.rect.height / 2 - 32)))

        pass
