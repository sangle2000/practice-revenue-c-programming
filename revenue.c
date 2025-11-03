#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	long revenue[12][3];
	
	// Init revenue
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 3; j++){
			revenue[i][j] = 0;
		}
	}
	
	do {
		printf("Revenue\n");
		printf("1. Update information\n");
		printf("2. Check income\n");
		printf("3. Total revenue\n");
		printf("4. Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1: {
				int month, updateChoice;
				
				printf("1. January\n");
				printf("2. February\n");
				printf("3. March\n");
				printf("4. April\n");
				printf("5. May\n");
				printf("6. June\n");
				printf("7. July\n");
				printf("8. August\n");
				printf("9. September\n");
				printf("10. October\n");
				printf("11. November\n");
				printf("12. December\n");
				
				printf("Enter month:");
				scanf("%d", &month);
				
				do {
					printf("1. Update funds\n");
					printf("2. Update income\n");
					printf("3. Exit\n");	
					
					printf("Enter your choice:");
					scanf("%d", &updateChoice);
					
					switch (updateChoice) {
						case 1: {
							long updateFund;
							printf("Enter your update fund:");
							scanf("%ld", &updateFund);
							
							revenue[month-1][0] = updateFund;
							
							// Update interest
							revenue[month-1][2] = revenue[month-1][1] - revenue[month-1][0];
							
							printf("Update interest: %ld\n", revenue[month-1][2]);
							
							break;
						}
						case 2: {
							long updateIncome;
							printf("Enter your update income:");
							scanf("%ld", &updateIncome);
							
							revenue[month-1][1] = updateIncome;
							
							// Update interest
							revenue[month-1][2] = revenue[month-1][1] - revenue[month-1][0];
							printf("Update interest: %ld\n", revenue[month-1][2]);
							break;
						}
						case 3: {
							printf("Exiting...\n");
							break;
						}
						default:
							printf("Invalid choice\n");
					}
				} while (updateChoice != 3);
				
				break;
			}
			case 2: {
				int month;
				
				printf("1. January\n");
				printf("2. February\n");
				printf("3. March\n");
				printf("4. April\n");
				printf("5. May\n");
				printf("6. June\n");
				printf("7. July\n");
				printf("8. August\n");
				printf("9. September\n");
				printf("10. October\n");
				printf("11. November\n");
				printf("12. December\n");
				
				printf("Enter month:");
				scanf("%d", &month);
				
				long monthRevenue = revenue[month-1][2];
				
				printf("Revenue of month %d: %ld\n", month, monthRevenue);
				break;
			}
			case 3: {
				long totalRevenue = 0;
				
				for (int i = 0; i < 12; i++){
					totalRevenue += revenue[i][2];
				}
				
				printf("Total revenue is: %ld\n", totalRevenue);
				
				break;
			}
			case 4:
				printf("Exiting....\n");
				break;
		}
	} while (choice != 4);
	
	return 0;
}
