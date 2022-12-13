import powerlaw
import numpy as np
import os

base = 3600
end = 3600*48
theoretical_distribution = powerlaw.Power_Law(xmin=base, parameters=[2.5])



f=open("generate.data","a")
for i in range(2000):
    simulated_data = theoretical_distribution.generate_random(10000)
    res_list = []
    for elem in simulated_data:
        if elem <= end:
            res_list.append(elem)
    data = np.array(res_list)
    
    np.savetxt(f,data,fmt='%d')
f.close()    
