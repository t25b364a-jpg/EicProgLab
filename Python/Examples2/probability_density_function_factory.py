from expectation_estimator_exception import ExpectationEstimatorException
from pdf_uniform import Uniform
from pdf_beta import Beta
from pdf_norm import Norm
from pdf_gamma import Gamma

class ProbabilityDensityFunctionFactory:

    obj_list = [ 
                Uniform(), 
                Beta(),
                Norm(),
                Gamma()
                ]
            
    @classmethod
    def get_menu(cls): 
        menu = ''
        for idx in range(len(cls.obj_list)):
            menu += '{0}.\t {1}\n'.format(idx+1,cls.obj_list[idx].name)        
        return menu
        
    @classmethod
    def create(cls,name):
        if name == '1' or name == Uniform().name:
            return Uniform()
        elif name == '2' or name == Beta().name:
            return Beta()
        elif name == '3' or name == Norm().name:
            return Norm()
        elif name == '4' or name == Gamma().name:
            return Gamma()
        else:
            raise ExpectationEstimatorException(name  + ' は無効です．')
        
