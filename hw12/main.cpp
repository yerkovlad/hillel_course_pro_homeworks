#include "TaskController.hpp"
#include "TaskManager.hpp"
#include "TaskView.hpp"
#include <iostream>

int main() {
    TaskManager manager;
    TaskView view;
    TaskController controller(manager, view);

    while (true) {
        std::cout << "1. Add Task\n2. Show Tasks\n3. Sort Tasks\n4. Filter Tasks\n"
                  << "5. Mark Task as Done\n6. Edit Task\n7. Delete Task\n8. Exit\n";
        int choice = view.getIntegerInput("Choose an option: ");

        switch (choice) {
            case 1: controller.addTask(); break;
            case 2: controller.showTasks(); break;
            case 3: controller.sortTasks(); break;
            case 4: controller.filterTasks(); break;
            case 5: controller.markTaskAsDone(); break;
            case 6: controller.editTask(); break;
            case 7: controller.deleteTask(); break;
            case 8: return 0;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
