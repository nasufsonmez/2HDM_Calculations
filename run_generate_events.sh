#!/bin/bash

# 1 : DECAY  37     4.16561475e-01 : Gamma_W =  5  Gamma_H
# 2 : DECAY  37     2.08458166e+00 : Gamma_W =     Gamma_H
# 3 : DECAY  37     1.04328506e+01 : Gamma_W = 1/5 Gamma_H

name=hdecay
WORK_DIR=`pwd`

#if [ -d $folder ]
#then
#	echo "$folder exist recreating "
#	rm -rf $folder
#fi
#if [ -d $folder ]
#then
#	echo "$folder exist recreating "
#	rm -rf $folder
#fi

######################################
for i in 70 80 90 100 110 120 130
do

	for j in 1 2 3
	do

		suffix=MASS${i}_${j}

		folder=SingleTop_tj_${name}_2HDMC_${suffix}

		echo "#######################################################################"
		echo "It is working on $suffix\n"
		# Create working area
		#folder=MadGraph-${suffix}

		# make thge directory and copy the MadGraph files
		#mkdir $folder
		#cp -rf MadGraph5_v1_5_13/* $folder/
		MG_DIR=${WORK_DIR}/MG5_aMC_v2_2_2

		cd ${WORK_DIR}

		if [ ! -d ${MG_DIR}/${folder} ]
		then

			# copy the MGME folder, param_cards and model files
			if [ -d ${MG_DIR}/models/2HDMC_${suffix} ]
			then
				rm -r ${MG_DIR}/models/2HDMC_${suffix}
			fi

			cp -rf MGME/2HDMC  ${MG_DIR}/models/2HDMC_${suffix}
			cp param_card_${i}_${j}.lha  ${MG_DIR}/models/2HDMC_${suffix}/param_card.dat
		
			cp ${WORK_DIR}/${name}_proc_card_mg5.dat ${MG_DIR}/proc_card_mg5.dat
			
			#do the relevant changes for renaming the tag
			gsed -i "s/output process/output SingleTop_tj_${name}_2HDMC_${suffix}/" ${MG_DIR}/proc_card_mg5.dat
			gsed -i "s/MODELFOLDER/2HDMC_${suffix}/" ${MG_DIR}/proc_card_mg5.dat

			#compile the model files
			cd ${MG_DIR}/models/2HDMC_${suffix}
			rm *.o
			make
	
			# generate all relevant subprocesses
			cd ${MG_DIR};  ./bin/mg5_aMC proc_card_mg5.dat
	
			cd SingleTop_tj_${name}_2HDMC_${suffix}
	
			cp ${WORK_DIR}/${name}_run_card.dat  Cards/run_card.dat
			gsed -i "s/process     = run_tag/SingleTop_tj_${name}_2HDMC_${suffix}     = run_tag/" Cards/run_card.dat
		#else
			#continue;
			# multicore run
			cp me5_configuration.txt SingleTop_tj_${name}_2HDMC_${suffix}/Cards
			cd SingleTop_tj_${name}_2HDMC_${suffix}

			./bin/cleanall
			rm -rf Source/MODEL/*.o

			#for i in 1 2 3 4 5 6 7
			#do
				./bin/generate_events 2 8 ${suffix} 
			#done
			#./bin/internal/make_madevent_tar
			#mv madevent.tar.gz madevent_${suffix}.tar.gz
		fi

		echo "Done on `date`"

	done

done



#mkdir ${suffix}
#mv madevent_${suffix}.tar.gz ${suffix}/

#tar xzf madevent_${suffix}.tar.gz

#for i in 1 2 3 4 5 6 7
#do
#	./run.sh 100000 $RANDOM
#	mv events.lhe.gz
#done	
	
######################################
