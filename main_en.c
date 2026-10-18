#include <stdio.h>
#include <stdbool.h>

void show_menu() {
    printf("\n========== Menu ==========\n");
    printf("1. Display all grades\n");
    printf("2. Calculate average\n");
    printf("3. Find highest and lowest scores\n");
    printf("4. Count grade ranges\n");
    printf("5. Exit\n");
    printf("Please select (1-5): ");
}

void show_scores(int marks[], int numbers) {
    for (int i = 1; i <= numbers; i++) {
        printf("Student %d grade is %d\n", i, marks[i - 1]);
    }
}

float calculate_average(int marks[], int numbers) {
    int sum = 0;
    for (int i = 1; i <= numbers; i++) {
        sum = sum + marks[i - 1];
    }
    float average = (float)sum / numbers;
    return average;
}

int find_max(int marks[], int numbers) {
    int max = marks[0];
    for (int i = 1; i <= numbers; i++) {
        if (marks[i - 1] > max) {
            max = marks[i - 1];
        }
    }
    return max;
}

int find_min(int marks[], int numbers) {
    int min = marks[0];
    for (int i = 1; i <= numbers; i++) {
        if (marks[i - 1] < min) {
            min = marks[i - 1];
        }
    }
    return min;
}

void count_grades(int marks[], int numbers) {
    int grade_a = 0, grade_b = 0, grade_c = 0, grade_d = 0, grade_e = 0;

    for (int i = 0; i < numbers; i++) {
        if (marks[i] <= 59) {
            grade_e++;
        } else if (marks[i] <= 69) {
            grade_d++;
        } else if (marks[i] <= 79) {
            grade_c++;
        } else if (marks[i] <= 89) {
            grade_b++;
        } else {
            grade_a++;
        }
    }
    printf("\nExcellent (90-100): %d\n", grade_a);
    printf("Good (80-89): %d\n", grade_b);
    printf("Average (70-79): %d\n", grade_c);
    printf("Pass (60-69): %d\n", grade_d);
    printf("Fail (0-59): %d\n", grade_e);
}

int input_student_numbers() {
    int numbers = 1;
    float numbers_interim;
    
    do {
        if (numbers <= 0) {
            printf("Number of students must be a positive integer.\n");
        } else if (numbers > 50) {
            printf("Number of students cannot exceed 50.\n");
        }
        printf("Enter number of students (max 50, decimals will be rounded down): ");
        scanf("%f", &numbers_interim);
        numbers = (int)numbers_interim;
    } while (numbers <= 0 || numbers > 50);
    
    return numbers;
}
// Note: The 'if' checks the PREVIOUS input. 
// The initial value '1' ensures the first run doesn't trigger a false error.

void input_scores(int marks[], int numbers) {
    float marks_interim = 1;
    printf("\nEnter student grades (will be rounded down):");
    
    for (int i = 1; i <= numbers; i++) {
        do {
            if (marks_interim < 0) {
                printf("Grade cannot be negative.\n");
            } else if (marks_interim > 100) {
                printf("Grade cannot exceed 100.\n");
            }
            printf("\nStudent %d grade: ", i);
            scanf("%f", &marks_interim);
            marks[i - 1] = (int)marks_interim;
        } while (marks_interim < 0 || marks_interim > 100);
    }
}

int main() {
    int student_marks[50]; // Stores student grades

    int student_numbers = input_student_numbers();
    input_scores(student_marks, student_numbers);
    
    bool running = true;
    while (running) {
        show_menu();
        int choice;
        float choice_interim;

        scanf("%f", &choice_interim);
        choice = (int)choice_interim;
        
        switch (choice) {
            case 1:
                show_scores(student_marks, student_numbers);
                break;
            case 2:
                printf("Average grade is %.2f\n", calculate_average(student_marks, student_numbers));
                break;
            case 3:
                printf("\nMax score: %d, Min score: %d\n", find_max(student_marks, student_numbers), find_min(student_marks, student_numbers));
                break;
            case 4:
                count_grades(student_marks, student_numbers);
                break;
            case 5:
                running = false;
                printf("Thank you for using. Goodbye!\n");
                break;
            default:
                printf("Invalid input, please try again!\n");
                break;
        }
    }
    return 0;
}
