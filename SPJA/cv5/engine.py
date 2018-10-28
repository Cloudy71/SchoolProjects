import sys
from random import Random

import pygame

from Enemy1 import Enemy1
from Enemy2 import Enemy2
from Enemy3 import Enemy3
from Enemy4 import Enemy4
from Enemy5 import Enemy5
from Player import Player

from Missile import Missile
from Pod import Pod
from Shield import Shield

EVENT_SPAWN_ENEMY = pygame.USEREVENT
EVENT_SPAWN_POWERUP = pygame.USEREVENT + 1

"""
Implement the following functionality into the game:

(1 point)
Periodically spawn an enemy at the top of the window (@Engine.spawn_enemy).
The starting X position of the enemy should be random (and within the window width).
The enemy will move down in every frame according to its speed and delta (@Enemy.update).

(1 point)
Store health for the player and draw it in every frame below the score (@Player).

(2 points)
When the enemy hits the player, kill the enemy and decrease player health (@Enemy.update).
When the enemy moves out of the window, kill enemy an decreate player health.
When player health reaches zero, end the program.
    + randomly select enemy image (enemy1-5.gif) (0.5 points)
    + assign different starting health and score to the enemy according to its image (0.5 points)

(3 points)
When the player presses space, create a missile at the location of the player (@Player.handle_keys).
The missile will move up in every frame (@Missile.update).
When the missile hits an enemy, decrease the enemy's health according to the missile's damage.
If this kills the enemy, remove the enemy and add its score to player.
Remove the missile after it hits an enemy or leaves the window.
    + add cooldown to the missile firing (e.g. you can only fire once every 100 ms) (0.5 points)
    + play a sound when an enemy explodes (0.5 points)
    + add an explosion animation to the game for 2 seconds when an enemy explodes (1 bonus point)


Use the delta time in update method for all movements and animations.

Documentation: https://www.pygame.org/docs/index.html
Cheatsheet:
    # (pseudo-)random numbers
    import random
    r = random.Random()
    r.random()              # random number between in range (0, 1)
    r.randint(3, 5)         # random number in range [3, 5]
    r.choice([1, 2, 3])     # randomly select item from collection

    X coordinate is increasing from left to right
    Y coordinate is increasing from top to bottom

    # sprite groups
    g = pygame.sprite.Group()   # group of sprites
    e = Enemy(...)              # create sprite
    g.add(e)                    # add sprite to group
    g.update(arg1, arg2, ...)   # call .update(arg1, arg2, ...) on all sprites in group
    e.kill()                    # automatically remove sprite from all groups

    img = load_image('images/...')  # load image
    rect = img.get_rect()           # get image rectangle
    rect.center = (50, 50)          # set image center to (50, 50)

    surface.blit(img, rect)         # draw `img` at position specified by rectangle `rect`

    for sprite in g:                # draw all sprites from group
        g.draw(surface)

    engine.screen                   # window screen
    engine.screen.get_width()       # window width
    engine.screen.get_height()      # window height

    def update(self, engine, delta):
        self.rect = self.rect.move(500 * delta, 0) # move rectangle in X axis by 500 * delta

    from utils import Cooldown
    cd = Cooldown(500)          # 500 ms cooldown
    cd.update(delta)            # update cooldown in every frame
    if cd.reset_if_ready():     # returns True if CD is ready and resets it if its ready

    def handle_keys(self, event):
        if event.type == KEYDOWN:
            if event.key == K_LEFT:
                pass

    # return all sprites from collection `items` that collide with `player`
    collisions = pygame.sprite.spritecollide(player, items, False)
    if collisions:
        for item in collisions: # remove all items that collided with `player`
            item.kill()
"""


class Engine:
    def __init__(self, width=640, height=480):
        pygame.init()

        pygame.display.set_caption('SPJA invaders - MIL0068')
        pygame.key.set_repeat(100, 30)
        pygame.time.set_timer(EVENT_SPAWN_ENEMY, 2900)
        pygame.time.set_timer(EVENT_SPAWN_POWERUP, 3000)

        self.width = width
        self.height = height
        self.screen = pygame.display.set_mode((self.width, self.height))

        self.clock = pygame.time.Clock()
        self.delta = 0

        self.player = Player(self, (self.width / 2, self.height - 20))
        self.enemies = pygame.sprite.Group()
        self.missiles = pygame.sprite.Group()
        self.sprites = pygame.sprite.Group()
        self.powerups = pygame.sprite.Group()
        self.random = Random()

        pygame.mixer.init()
        self.sound_explosion = pygame.mixer.Sound("sound/explosion.wav")
        self.sound_explosion.set_volume(0.1)

        self.spawn_enemy()
        self.spawn_powerup()

    def main_loop(self):
        self.background = pygame.Surface(self.screen.get_size())
        self.background = self.background.convert()
        self.background.fill((0, 0, 0))

        while True:
            self.delta = self.clock.tick(60) / 1000
            self.handle_keys()
            self.update()
            self.draw()

    def handle_keys(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == EVENT_SPAWN_ENEMY:
                self.spawn_enemy()
            elif event.type == EVENT_SPAWN_POWERUP:
                self.spawn_powerup()
            else:
                self.player.handle_keys(event, self.delta)

    def update(self):
        self.enemies.update(self, self.delta)
        self.missiles.update(self, self.delta)
        self.player.update(self, self.delta)
        self.powerups.update(self, self.delta)
        self.sprites.update(self, self.delta)

        if self.player.health <= 0 and (len(self.enemies) > 0 or len(self.missiles) > 0):
            self.enemies.empty()
            self.missiles.empty()
            self.powerups.empty()

    def draw(self):
        self.screen.blit(self.background, (0, 0))

        for enemy in self.enemies:
            enemy.draw(self.screen)

        for missile in self.missiles:
            missile.draw(self.screen)

        for powerup in self.powerups:
            powerup.draw(self.screen)

        for sprite in self.sprites:
            sprite.draw(self.screen)

        self.player.draw(self.screen)

        pygame.display.flip()

    def spawn_enemy(self):
        types = 0
        amount = 1
        if self.player.score >= 0:
            types += 1
        if self.player.score > 1_000:
            types += 1
        if self.player.score > 3_000:
            types += 1
            amount += 1
        if self.player.score > 5_000:
            types += 1
        if self.player.score > 8_000:
            types += 1
            amount += 1

        for i in range(amount):
            # Spawning enemies is based on player's score.
            type = self.random.randint(1, types)
            x = self.random.randint(0, self.width - 32)
            y = 0

            if type == 1:
                self.enemies.add(Enemy1([x, y]))
            elif type == 2:
                self.enemies.add(Enemy2([x, y]))
            elif type == 3:
                self.enemies.add(Enemy3([x, y]))
            elif type == 4:
                self.enemies.add(Enemy4([x, y]))
            elif type == 5:
                self.enemies.add(Enemy5([x, y]))
        pass

    def spawn_missile(self):
        missile = Missile(self.player, (self.player.rect.left + 14, self.player.rect.top + 6))
        self.missiles.add(missile)

    def spawn_powerup(self):
        type = self.random.randint(0, 1)
        pos = (self.random.randint(0, self.width - 24), self.height - self.player.forward_max_y + 32)
        obj = None
        if type == 0:
            obj = Shield(pos)
        elif type == 1:
            obj = Pod(pos)
        self.powerups.add(obj)


if __name__ == '__main__':
    engine = Engine()
    engine.main_loop()
