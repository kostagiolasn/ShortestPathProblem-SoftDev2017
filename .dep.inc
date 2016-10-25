# This code depends on make tool being used
<<<<<<< HEAD
DEPFILES=$(wildcard $(addsuffix .d, ${OBJECTFILES}))
=======
DEPFILES=$(wildcard $(addsuffix .d, ${OBJECTFILES} ${TESTOBJECTFILES}))
>>>>>>> 6abf377cff4424ec554c767478a877b380c599e3
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
