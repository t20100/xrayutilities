import xrutils as xu
import numpy
#import matplotlib.pyplot as plt

#en = (2*8048 + 8028)/3.
en = 8048
peak_width = 2*numpy.pi/100.
resolution = peak_width/10.

# create Fe BCC with a=2.87Angstrom
FeBCC = xu.materials.Material("Fe", xu.materials.BCCLattice(xu.materials.elements.Fe,2.87),numpy.zeros((6,6), dtype=numpy.double))

print("Creating Fe powder ...")
Fe_powder = xu.Powder(FeBCC,en=en)
Fe_powder.PowderIntensity()
Fe_th,Fe_int = Fe_powder.Convolute(resolution,peak_width)

#plt.figure(1)
#plt.clf()
#ax1 = plt.subplot(111)
#plt.xlabel(r"$2\theta$ (deg)")
#plt.ylabel(r"Intensity")
##plt.semilogy(Fe_th*2,Fe_int/Fe_int.max(),'k-',linewidth=2.)
#plt.plot(Fe_th*2,Fe_int/Fe_int.max(),'k-',linewidth=2.)
#ax1.set_xlim(0,160)
#ax1.set_ylim(0.001,1.2)
#plt.grid()


