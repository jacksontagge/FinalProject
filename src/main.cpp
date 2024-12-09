#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum WorkoutType {STRENGTH, SWIM, BIKE, RUN, STRETCH};

class Workout {
public:
    string date;
    WorkoutType type;
    int duration;
    int caloriesBurned;
    double distance;

    Workout(string date, WorkoutType type, int duration, int caloriesBurned, double distance)
     : date(date), type(type), duration(duration), caloriesBurned(caloriesBurned), distance(distance) {}

    void showWorkout() const {
        const string workoutTypeNames[] = {"Strength", "Swim", "Bike", "Run", "Stretch"};
        cout << "Date: " << date << endl;
        cout << "Workout Type: " << workoutTypeNames[type] << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Calories Burned: " << caloriesBurned << " cal" << endl;
        cout << "Distance: " << distance << " miles" << endl;
    }
};

class Nutrition {
public:
    string date;
    int calories;
    int protein;
    int carbs;
    int fiber;
    int fats;
    int sugars;

    Nutrition(string date, int calories, int protein, int carbs, int fiber, int fats, int sugars)
     : date(date), calories(calories), protein(protein), carbs(carbs), fiber (fiber), fats(fats), sugars(sugars) {}

    void displayNutrition() const {
        cout << "Date: " << date << endl;
        cout << "Nutrition info:\n";
        cout << "Calories: " << calories << "cal\n";
        cout << "Protein: " << protein << "g\n";
        cout << "Carbs: " << carbs << "g\n";
        cout << "Fiber: " << fiber << "g\n"; 
        cout << "Fats: " << fats << "g\n";
        cout << "Sugar: " << sugars << "g\n";
    }
};

Workout logWorkout() {
    string date;
    int type;
    int duration;
    int caloriesBurned;
    double distance;
    WorkoutType workoutType;

    cout << "Enter date of workout (month-day-year): ";
    cin >> date;
    cout << "Enter workout type (0 = Strength training, 1 = Swim, 2 = Bike, 3 = Run, 4 = Stretch): ";
    cin >> type;
    if (type == 0) {
        workoutType = STRENGTH;
    } else if (type == 1) {
        workoutType = SWIM;
    } else if (type == 2) {
        workoutType = BIKE;
    } else if (type == 3) {
        workoutType = RUN;
    } else if (type == 4) {
        workoutType = STRETCH;
    } else {
        cout << "Invalid selction! Default to Strength training" << endl;
        workoutType = STRENGTH;
    }
    cout << "Enter workout duration (in minutes): ";
    cin >> duration;
    cout << "Enter the number of calories burned during workout: ";
    cin >> caloriesBurned;
    cout << "Enter the distance: ";
    cin >> distance;

    return Workout(date, workoutType, duration, caloriesBurned, distance);

}

Nutrition logNutrition() {
    string date;
    int calories;
    int protein;
    int carbs;
    int fiber;
    int fats;
    int sugars;

    cout << "Enter date of workout (month-day-year): ";
    cin >> date;
    cout << "Enter total calories: ";
    cin >> calories;
    cout << "Enter total protein (grams): ";
    cin >> protein;
    cout << "Enter total carbs (grams): ";
    cin >> carbs;
    cout << "Enter total fiber (grams): ";
    cin >> fiber;
    cout << "Enter total fats (grams): ";
    cin >> fats;
    cout << "Enter total sugars (grams): ";
    cin >> sugars;

    return Nutrition(date, calories, protein, carbs, fiber, fats, sugars);

}

int main() {
    vector <Workout> workouts;
    vector <Nutrition> nutritionLogs;
    int choice;

    do {
        cout << "\n1. Log a new workout\n";
        cout << "2. View all workouts\n";
        cout << "3. Log nutrition\n";
        cout << "4. View nutrition logs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Workout newWorkout = logWorkout();
            workouts.push_back(newWorkout);
        } else if (choice == 2) {
            cout << "\nLogged Workouts: \n";
            for (const Workout& workout : workouts) {
                workout.showWorkout();
                cout << "-------------------" << endl;
            }
        } else if (choice == 3) {
            Nutrition newNutition = logNutrition();
            nutritionLogs.push_back(newNutition);
        } else if (choice == 4) {
            cout << "\nLogged Nutrition:\n";
            for (const Nutrition& nutrition : nutritionLogs) {
                nutrition.displayNutrition();
                cout << "-------------------" << endl;
            }
        }
    } while (choice != 5);

    cout << "Exiting program..." << endl;
    return 0;
}
