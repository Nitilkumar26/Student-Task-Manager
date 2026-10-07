#include <stdio.h>
#include <string.h>

#define MAX_TASKS 20

struct Task {
    char name[100];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\nTask limit reached!\n");
        return;
    }

    printf("\nEnter task: ");
    getchar();
    fgets(tasks[taskCount].name, 100, stdin);

    tasks[taskCount].name[
        strcspn(tasks[taskCount].name, "\n")
    ] = '\0';

    tasks[taskCount].completed = 0;
    taskCount++;

    printf("Task added successfully!\n");
}

void viewTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n========== YOUR TASKS ==========\n");

    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n",
               i + 1,
               tasks[i].name,
               tasks[i].completed ? "Completed" : "Pending");
    }
}

void completeTask() {
    int number;

    viewTasks();

    if (taskCount == 0)
        return;

    printf("\nEnter task number to mark completed: ");
    scanf("%d", &number);

    if (number >= 1 && number <= taskCount) {
        tasks[number - 1].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

void deleteTask() {
    int number;

    viewTasks();

    if (taskCount == 0)
        return;

    printf("\nEnter task number to delete: ");
    scanf("%d", &number);

    if (number >= 1 && number <= taskCount) {

        for (int i = number - 1; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        taskCount--;

        printf("Task deleted successfully!\n");

    } else {
        printf("Invalid task number!\n");
    }
}

int main() {

    int choice;

    while (1) {

        printf("\n\n================================\n");
        printf("       STUDENT TASK MANAGER\n");
        printf("================================\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                printf("\nThank you for using Student Task Manager!\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}