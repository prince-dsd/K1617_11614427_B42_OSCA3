#include <stdio.h>
#include <stdlib.h>
double page_fault_rate();
void userInput(void);

double service_page_fault_empty;
double service_page_fault_modified;
double mem_access_time;
double times_page_modified;
double effective_access_time;
double pageFaultRate;
double service_page_fault_empty_ns;
double service_page_fault_modified_ns;
double times_page_modified_per;
	

void main(){
	int swtch;
	
	do{
	
	
	printf("\n Select the required option \n");
	printf("1.Find the PageFault Rate\n");
	printf("2.Exit");
	scanf("%d",&swtch);
	switch(swtch){
		case 1:userInput();break;
		case 2:exit(0);
	}

}while(swtch<3);
}
void userInput(){
	
	
	printf("\nEnter service Page Fault [Empty|Page is not Modified]");
	scanf("%lf",&service_page_fault_empty);
	printf("Enter Service Page Fault [Modified Page]");
	scanf("%lf",&service_page_fault_modified);
	printf("Enter Memory Access Time");
	scanf("%lf",&mem_access_time);
	printf("Enter Percentage of time the page to be replaced is modified[0-100]");
	scanf("%lf",&times_page_modified);
	printf("Enter Effective Access time");
	scanf("%lf",&effective_access_time);
    printf("Page Fault rate for the Above values"); 
	service_page_fault_empty_ns = (service_page_fault_empty*1000000);
	service_page_fault_modified_ns = (service_page_fault_modified*1000000);
	times_page_modified_per = (times_page_modified/100);   
    pageFaultRate =  page_fault_rate(service_page_fault_empty_ns,service_page_fault_modified_ns,mem_access_time,times_page_modified_per,effective_access_time);
	printf("Page Fault rate = %e",pageFaultRate);


}

double page_fault_rate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double numErator,denOminator;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 numErator = effAccess - memAccess;
     denOminator = (assume+serve);

	pageFault = numErator/denOminator;
	return pageFault;


}

