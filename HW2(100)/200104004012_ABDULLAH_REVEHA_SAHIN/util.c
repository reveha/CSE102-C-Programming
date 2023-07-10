#include <stdio.h>
#include <math.h>
#include "util.h"



/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

char dt1a(double pl, double pw, double sl, double sw){
	char returned_value; // i will return this variable at the end of the function.
	
	if(pl<2.45){ // root node
		returned_value='s';
	}
	else{
		if(pw<1.75){
			if(pl<4.95){
				if(pw<1.65){
					returned_value='V'; // V means versicolor
				
				}
				else{
					returned_value='v';//v means virginica
				}
			}
			else{
				returned_value='v'; //v means virginica
			}
			
		}	
		else{
			returned_value='v'; //v means virginica
		}	
		
	}
	
	return returned_value;
}

char dt1b(double pl, double pw, double sl, double sw){
	char returned_value; // i will return this variable at the end of the function.
	if(pl<2.55){ // root node
		returned_value='s'; //v means setosa
	}	
	else{
		if(pw<1.69){
			if(pl<4.85){
				returned_value='V'; //v means versicolor
			}
			else{
				returned_value='v'; //v means virginica
			}
			
		}
		else{
			returned_value='v'; //v means virginica
		}
	}
	return returned_value;
}

double dt2a(double x1, double x2, double x3, int x4, int x5){
	double returned_value; // i will return this variable at the end of the function.
	if(x1<31.5){ // root node
		if(x2>-2.5){
			returned_value=5.0;
		}
		else{
			if(x2-0.1<=x1 && x1<=x2+0.1){
				returned_value=2.1;
			}
			else{
				returned_value=-1.1;
			}
			
		}
		
	}
	else{
		if(-1<=x3 && x3<=2){
			returned_value=1.4;
		}
		else{
			if(x4 && x5){
				returned_value=-2.23;
			}
			else{
				returned_value=11.0;
			}	
		}
	}
	
	return returned_value;
}

double dt2b(double x1, double x2, double x3, int x4, int x5){
	double returned_value; // i will return this variable at the end of the function.
	if(12<x1 && x1<22){ // root node
		if(x3>(double)5/3){
			returned_value=-2.0;
		}
		else{
			if(x1-0.1<=x3 && x3<=x1+0.1){
				returned_value=1.01;
			}
			else{
				returned_value=-8;
			}
		}
	}
	else{
		if(x4 && x5){
			returned_value=-1;
		}
		else{
			if(-1<=x2 && x2<=2){
				returned_value=-1/7;
			}
			else{
				returned_value=sqrt(2)/3; 
			}
		}
	}
	
	return returned_value;
}




double dt3a(int laptop_or_not, int cpu, int gpu, double free_ram, double free_capacity){
	/*
		not enough cpu are 1, 2, 5, 6, 11, 13 for this function.
		not enough gpu are 1,2,3 for this function.
		having enough cpu and gpu are determined in the main.c
		This program is returning the FPS value according to your computer specs.	
		There must be at least 3.4 free ram, 96.5 free capacity, having enough gpu, having enough cpu, not having laptop to get best FPS value.
		If some of them are not in the computer, the FPS will decrease according to which part is not enough.
		this part only contains if and else blocks so i do not need to explain each statement. It is not necesarry.
	*/	
	
	double returned_value; // i will return this variable at the end of the function.
	if(free_capacity<96.5){ // root node
		returned_value=-1;  // that means there is no enough place to store program
	}
	else{
		if(free_ram<=3.4){
			if(laptop_or_not){
				if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
					if(3<gpu && gpu<9){
						returned_value=73.778;
					}
					else{
						returned_value=64.337;
					}
				}
				else{
					returned_value=47.755;
				}
			}
			else{
				if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
					if((3<gpu && gpu<9)){
						returned_value=100.598;
					}
					else{
						returned_value=88.390;
					}
				}
				else{
					returned_value=63.428;
				}
			}
		}
		else{
			if(laptop_or_not==1){
				if(free_ram<=12.3){
					if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
						returned_value=103.564;
					}
					else{
						returned_value=87.441;
					}
				}
				else{
					returned_value=128.704;
				}
			}
			else{
				if(3<gpu && gpu<9){
					returned_value=143.450;
				}
				else{
					if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
						returned_value=107.285;
					}
					else{
						returned_value=95.565;
					}
				}
			}
		}
	}
	
	return returned_value;	
}
double dt3b(int laptop_or_not, int cpu, int gpu, double free_ram, double free_capacity){
	/*	
		not enough cpu are 1, 2, 5, 6, 11, 13 for this function.
		not enough gpu are 1,2,3,4 for this function.
		having enough cpu and gpu are determined in the main.c
		This program is returning the FPS value according to your computer specs.	
		There must be at least 4.2 free ram, 96.5 free capacity, having enough gpu, having enough cpu, not having laptop to get best FPS value.
		If some of them are not in the computer, the FPS will decrease according to which part is not enough.
		this part only contains if and else blocks so i do not need to explain each statement. It is not necesarry.
	*/	


	double returned_value; // i will return this variable at the end of the function.
	if(free_capacity<96.5){ // root node
		return -1;  // that means there is no enough place to store program
	}
	else{
		if(4.2<=free_ram && free_ram<=8.5){
			if(4<gpu && gpu<9){
				if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
					if(laptop_or_not){
						returned_value=123.761;
					}
					else{
						returned_value=140.557;
					}
				}
				else{
					returned_value=109.580;
				}
			}
			else{
				if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
						returned_value=107.285;
					}
					else{
						returned_value=77.480;
					}
			}
		}
		else{
			if(4<gpu && gpu<9){
				if(free_ram<4.2){
					returned_value=78.885;
				}
				else{
					if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
						returned_value=157.339;
					}
					else{
						returned_value=138.552;
					}
				}
			}
			else{
				if(cpu!=1 && cpu!=2 && cpu!= 5 && cpu!=6 && cpu!=11 && cpu!=13){
						if(laptop_or_not){
							returned_value=89.551;
						}
						else{
							returned_value=99.690;
						}
					}
				else{
					if(free_ram>8.5){
						returned_value=83.160;
					}
					else{
						returned_value=47.775;
					}
				}
			}
		}
	}	
	return returned_value;
}



/* Provide your implementations for all the requested functions here */
