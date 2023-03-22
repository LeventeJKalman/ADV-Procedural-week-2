#include <stdio.h>
#include <string.h>

typedef struct {
	char employeeName[30];
	int employeeID;
	float hours;
	float hourlyRate;
}employeeT;

void main() {
	employeeT emps;
	employeeT empAppend;

	FILE* fp;

	fp = fopen("employee.txt","r");

	if (fp == NULL) {
		printf("Cannot open file");
	}
	else {
			while (!feof(fp)) {
				int numInputs = fscanf(fp, "%s %d %f %f", emps.employeeName, &emps.employeeID, &emps.hours, &emps.hourlyRate);
				if (numInputs == numInputs)
				{
					printf("\nEmployee Name: %s\nEmployee ID: %d\nHours Worked: %.2f\nHourly Rate: %.2f\n",
						emps.employeeName, emps.employeeID, emps.hours, emps.hourlyRate);
				}		
			}	
			fclose(fp);
	}
			

	fp = fopen("employee.txt", "a");

	if (fp == NULL) {
		printf("Cannot open file to append");
	}
	else {
		int amount = printf("\nHow many employees would you like to add?\n");		
		scanf("%d", &amount);

		for (int i = 0; i < amount; i++) {
			printf("\nPlease enter employee name: \n");
			scanf(" %s", empAppend.employeeName);
			fprintf(fp, "\n%s ", empAppend.employeeName);

			printf("Please enter employee ID: \n");
			scanf(" %d", &empAppend.employeeID);
			fprintf(fp, "%d ", empAppend.employeeID);

			printf("Please enter hours worked: \n");
			scanf("%f", &empAppend.hours);
			fprintf(fp, "%.2f ", empAppend.hours);

			printf("Please enter hourly rate: \n");
			scanf("%f", &empAppend.hourlyRate);
			fprintf(fp, "%.2f", empAppend.hourlyRate);

			printf("Employee was added to the file.\n");
		}
	}
}