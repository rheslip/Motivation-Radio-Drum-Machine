modified version of Paul Stoffregen's wav2sketch utility https://raw.githubusercontent.com/PaulStoffregen/Audio/master/extras/wav2sketch/wav2sketch.c

creates the required sample header files for the MORAD_Drums sketch

usage: put your 22 or 44khz samples into a subdirectory within the sketch folder along with a copy of the utility. 

run wav2header - it will generate header files for all the samples (note that it may change the names to make them C compatible). 44khz samples will be resampled to 22khz

it also generates an include file "samples.h" with all the samples, and a sample table "sampledefs.h".

include file "samples.h" in the MORAD_DRums sketch - see the sketch for where to put this include (DON'T include it at the beginning!)

R Heslip Feb 2019

