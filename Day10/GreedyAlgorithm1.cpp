#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a1, Activity a2) {
    return a1.end < a2.end;
}

void maxActivities(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected Activities: \n";
    int last_end = 0;
    for (auto activity : activities) {
        if (activity.start >= last_end) {
            cout << "(" << activity.start << ", " << activity.end << ")\n";
            last_end = activity.end;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {5, 7}};
    
    maxActivities(activities);

    return 0;
}
