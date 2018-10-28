from GameObject import GameObject
from utils import load_image


class Beam(GameObject):
    def __init__(self, player, pos, speed=1000):
        super().__init__(load_image("images/beam.png"), pos)
        self.image.set_alpha(1)
        self.player = player
        self.speed = speed

    def update(self, engine, delta):
        self.rect = self.rect.move(0, self.speed * delta)

        if self.rect.top > engine.height:
            self.player.beams.remove(self)
        pass
