#!/bin/bash
Pexsi_DIR=/home/therlf/pexsi_v2.0.0
PARMETIS_DIR=/home/therlf/parmetis-4.0.3
SuperLU_DIR=/home/therlf/Software/SuperLU_DIST_install
INSTALL_DIR=/home/therlf/Software/Pexsi_install


BDIR=build
rm -rf ${BDIR}

cmake -H${Pexsi_DIR} -B${BDIR} \
    -DCMAKE_C_COMPILER=gcc \
    -DCMAKE_CXX_COMPILER=g++ \
    -DCMAKE_BUILD_TYPE=Release \
    -DPEXSI_DEBUG_LEVEL=1 \
    -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} \
    -DSuperLU_DIST_PREFIX=${SuperLU_DIR} \
    -DParMETIS_PREFIX=${PARMETIS_DIR}

make -j 12 -C ${BDIR} install

