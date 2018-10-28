from utils import load_image
from GameObject import GameObject


class Missile(GameObject):
    def __init__(self, player, pos, damage=50, speed=800):
        super().__init__(load_image('images/bullet.gif'), pos)

        self.player = player
        self.damage = damage
        self.speed = speed

    def update(self, engine, delta):
        """
        TODO: move missile up by self.speed * self.delta
        TODO:
        When missile hits enemy, kill missile and reduce enemy HP by self.damage.
        If enemy HP will be <= 0, kill the enemy and increase player score by enemy.score.
        TODO: when enemy moves out of the window, kill enemy and reduce player HP
        """

        self.rect = self.rect.move(0, -self.speed * delta)

        if self.rect.bottom < 0:
            engine.missiles.remove(self)

        pass

    pass
