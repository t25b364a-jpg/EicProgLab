from ipdf import IProbabilityDensityFunction
import random

class Gamma(IProbabilityDensityFunction):

    def parameter_inquiry(self):
        print('ガンマ分布のパラメータ(k, θ)を入力してください')
        self.k = float(input('k: '))
        self.theta = float(input('θ: '))

    def draw_sample(self):
        return random.gammavariate(self.k, self.theta  )

    @property
    def name(self):
        return 'ガンマ分布'

    @property
    def analytical_expectation(self):
        return self.k * self.theta

