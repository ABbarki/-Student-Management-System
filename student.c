#include <stdio.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    float grade;
};

int main(void)
{
    struct Student students[100];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Average\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        // Consume the newline left by scanf
        getchar();

        switch (choice) {

            case 1:
                if (count >= 100) {
                    printf("Student list is full!\n");
                    break;
                }

                students[count].id = 01 + count;

                printf("Enter student name: ");
                fgets(students[count].name,
                      sizeof(students[count].name), stdin);

                students[count].name[
                    strcspn(students[count].name, "\n")
                ] = '\0';

                printf("Enter student grade: ");

                if (scanf("%f", &students[count].grade) != 1) {
                    printf("Invalid grade!\n");
                    getchar();
                    break;
                }

                getchar();

                printf("Student added successfully!\n");
                printf("Student ID: %d\n",
                       students[count].id);

                count++;
                break;

            case 2:
                if (count == 0) {
                    printf("No students registered yet.\n");
                    break;
                }

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d | Name: %s | Grade: %.2f\n",
                           students[i].id,
                           students[i].name,
                           students[i].grade);
                }
                break;

            case 3: {
                char search_name[50];
                int found = 0;

                printf("Enter student name: ");
                fgets(search_name, sizeof(search_name), stdin);

                search_name[
                    strcspn(search_name, "\n")
                ] = '\0';

                for (int i = 0; i < count; i++) {
                    if (strcmp(students[i].name,
                               search_name) == 0) {

                        printf("\nStudent found!\n");
                        printf("ID: %d\n", students[i].id);
                        printf("Name: %s\n", students[i].name);
                        printf("Grade: %.2f\n", students[i].grade);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }

                break;
            }

            case 4: {
                if (count == 0) {
                    printf("No grades available.\n");
                    break;
                }

                float sum = 0;

                for (int i = 0; i < count; i++) {
                    sum += students[i].grade;
                }

                printf("Average grade: %.2f\n",
                       sum / count);

                break;
            }

            case 5:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Choose 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}

