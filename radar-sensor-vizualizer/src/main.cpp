#include <iostream>
using namespace std;

int main()
{
    // Sensor data

    int objectID[] = {1, 2, 3, 4, 5};
    int distance[] = {350, 460, 330, 110, 250};
    int angle[] = {30, 45, 67, 55, 86};
    int signal[] = {25, 45, 66, 98, 77};

    int totalObjects = sizeof(objectID) / sizeof(objectID[0]);

    int choice;

    do
    {
        cout << endl;
        cout << "============================================================" << endl;
        cout << "              RADAR / SENSOR DATA VISUALIZER" << endl;
        cout << "============================================================" << endl;

        cout << "Detected Objects: " << totalObjects << endl;

        cout << endl;
        cout << "========================= MAIN MENU =========================" << endl;
        cout << "1. Display all objects" << endl;
        cout << "2. Find closest object" << endl;
        cout << "3. Find farthest object" << endl;
        cout << "4. Find strongest signal" << endl;
        cout << "5. Search object by ID" << endl;
        cout << "6. Sort objects by distance" << endl;
        cout << "7. Show statistics" << endl;
        cout << "8. Generate sensor report" << endl;
        cout << "9. Exit" << endl;
        cout << "============================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            // Feature 1: Display all objects

            case 1:
            {
                cout << endl;
                cout << "====================== ALL OBJECTS =========================" << endl;

                cout << "ID        Distance(m)        Angle(°)        Signal" << endl;
                cout << "------------------------------------------------------------" << endl;

                for(int i = 0; i < totalObjects; i++)
                {
                    cout << objectID[i] << "        "
                         << distance[i] << "              "
                         << angle[i] << "             "
                         << signal[i] << endl;
                }

                cout << "============================================================" << endl;
                break;
            }


            // Feature 2: Find closest object

            case 2:
            {
                int nearestDistance = distance[0];
                int nearestObject = objectID[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(distance[i] < nearestDistance)
                    {
                        nearestDistance = distance[i];
                        nearestObject = objectID[i];
                    }
                }

                cout << endl;
                cout << "Closest Object ID: " << nearestObject << endl;
                cout << "Closest Distance: " << nearestDistance << " m" << endl;

                break;
            }


            // Feature 3: Find farthest object

            case 3:
            {
                int farthestDistance = distance[0];
                int farthestObject = objectID[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(distance[i] > farthestDistance)
                    {
                        farthestDistance = distance[i];
                        farthestObject = objectID[i];
                    }
                }

                cout << endl;
                cout << "Farthest Object ID: " << farthestObject << endl;
                cout << "Farthest Distance: " << farthestDistance << " m" << endl;

                break;
            }


            // Feature 4: Find strongest signal

            case 4:
            {
                int strongestSignal = signal[0];
                int signalObjectID = objectID[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(signal[i] > strongestSignal)
                    {
                        strongestSignal = signal[i];
                        signalObjectID = objectID[i];
                    }
                }

                cout << endl;
                cout << "Strongest Signal Object ID: " << signalObjectID << endl;
                cout << "Signal Strength: " << strongestSignal << endl;

                break;
            }


            // Feature 5: Search object by ID

            case 5:
            {
                int searchID;

                cout << endl;
                cout << "Enter the Object ID: ";
                cin >> searchID;

                bool found = false;

                for(int i = 0; i < totalObjects; i++)
                {
                    if(objectID[i] == searchID)
                    {
                        cout << endl;
                        cout << "Object Found!" << endl;
                        cout << "Object ID: " << objectID[i] << endl;
                        cout << "Distance: " << distance[i] << " m" << endl;
                        cout << "Angle: " << angle[i] << "°" << endl;
                        cout << "Signal: " << signal[i] << endl;

                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << endl;
                    cout << "Object ID " << searchID << " not found." << endl;
                }

                break;
            }


            // Feature 6: Sort objects by distance

            case 6:
            {
                for(int i = 0; i < totalObjects - 1; i++)
                {
                    int minIndex = i;

                    for(int j = i + 1; j < totalObjects; j++)
                    {
                        if(distance[j] < distance[minIndex])
                        {
                            minIndex = j;
                        }
                    }

                    // Swap distance

                    int temp = distance[i];
                    distance[i] = distance[minIndex];
                    distance[minIndex] = temp;

                    // Swap object ID

                    int tempID = objectID[i];
                    objectID[i] = objectID[minIndex];
                    objectID[minIndex] = tempID;

                    // Swap angle

                    int tempAngle = angle[i];
                    angle[i] = angle[minIndex];
                    angle[minIndex] = tempAngle;

                    // Swap signal

                    int tempSignal = signal[i];
                    signal[i] = signal[minIndex];
                    signal[minIndex] = tempSignal;
                }

                cout << endl;
                cout << "Objects sorted by distance:" << endl;

                for(int i = 0; i < totalObjects; i++)
                {
                    cout << "ID: " << objectID[i]
                         << " | Distance: " << distance[i]
                         << " m | Angle: " << angle[i]
                         << "° | Signal: " << signal[i] << endl;
                }

                break;
            }


            // Feature 7: Statistics

            case 7:
            {
                int totalDistance = 0;

                for(int i = 0; i < totalObjects; i++)
                {
                    totalDistance = totalDistance + distance[i];
                }

                double averageDistance =
                    (double)totalDistance / totalObjects;


                int smallestDistance = distance[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(distance[i] < smallestDistance)
                    {
                        smallestDistance = distance[i];
                    }
                }


                int largestDistance = distance[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(distance[i] > largestDistance)
                    {
                        largestDistance = distance[i];
                    }
                }


                int totalSignal = 0;

                for(int i = 0; i < totalObjects; i++)
                {
                    totalSignal = totalSignal + signal[i];
                }

                double averageSignal =
                    (double)totalSignal / totalObjects;


                cout << endl;
                cout << "===================== STATISTICS ===========================" << endl;

                cout << "Total Objects: " << totalObjects << endl;
                cout << "Average Distance: " << averageDistance << " m" << endl;
                cout << "Minimum Distance: " << smallestDistance << " m" << endl;
                cout << "Maximum Distance: " << largestDistance << " m" << endl;
                cout << "Average Signal: " << averageSignal << endl;

                cout << "============================================================" << endl;

                break;
            }


            // Feature 8: Sensor report

            case 8:
            {
                int nearestDistance = distance[0];
                int nearestObject = objectID[0];

                int farthestDistance = distance[0];
                int farthestObject = objectID[0];

                int strongestSignal = signal[0];
                int signalObjectID = objectID[0];

                for(int i = 1; i < totalObjects; i++)
                {
                    if(distance[i] < nearestDistance)
                    {
                        nearestDistance = distance[i];
                        nearestObject = objectID[i];
                    }

                    if(distance[i] > farthestDistance)
                    {
                        farthestDistance = distance[i];
                        farthestObject = objectID[i];
                    }

                    if(signal[i] > strongestSignal)
                    {
                        strongestSignal = signal[i];
                        signalObjectID = objectID[i];
                    }
                }


                int totalDistance = 0;
                int totalSignal = 0;

                for(int i = 0; i < totalObjects; i++)
                {
                    totalDistance += distance[i];
                    totalSignal += signal[i];
                }

                double averageDistance =
                    (double)totalDistance / totalObjects;

                double averageSignal =
                    (double)totalSignal / totalObjects;


                cout << endl;
                cout << "============================================================" << endl;
                cout << "                    SENSOR REPORT" << endl;
                cout << "============================================================" << endl;

                cout << endl;
                cout << "Objects Detected     : " << totalObjects << endl;

                cout << endl;
                cout << "Closest Object       : ID " << nearestObject << endl;
                cout << "Closest Distance     : " << nearestDistance << " m" << endl;

                cout << endl;
                cout << "Farthest Object      : ID " << farthestObject << endl;
                cout << "Farthest Distance    : " << farthestDistance << " m" << endl;

                cout << endl;
                cout << "Strongest Signal     : ID " << signalObjectID << endl;
                cout << "Signal Strength      : " << strongestSignal << endl;

                cout << endl;
                cout << "Average Distance     : " << averageDistance << " m" << endl;
                cout << "Average Signal       : " << averageSignal << endl;

                cout << endl;
                cout << "============================================================" << endl;

                break;
            }


            // Feature 9: Exit

            case 9:
            {
                cout << endl;
                cout << "Exiting Radar / Sensor Data Visualizer..." << endl;
                cout << "Thank you for using the program!" << endl;

                break;
            }


            // Invalid choice

            default:
            {
                cout << endl;
                cout << "Invalid choice! Please enter a number between 1 and 9." << endl;

                break;
            }
        }

    } while(choice != 9);


    return 0;
}