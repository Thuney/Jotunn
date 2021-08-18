all:
		make -C Jotunn
		make -C Applications		
clean:
		make clean -C Jotunn
		make clean -C Applications