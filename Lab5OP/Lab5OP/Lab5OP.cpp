#include <iostream>
#include "TPrism3.h"
#include "TPrism4.h"

using namespace std;

int main()
{
    int m;
    cout << "How many prism do you want to create" << endl;
    cin >> m;

    double previousVolume = 0.0;
    double sumOfVolumes = 0.0;
    double sumOfSurfaceAreas = 0.0;

    TPrism3* TriangularPrism = new TPrism3[m];
    TPrism4* QuadrangularPrism = new TPrism4[m];

    for (int i = 0; i < m; i++)
    {
        double TriangularHeight, QuadrangularHeight;
        double TriagleSide, RectSide;

        cout << "Enter the height and base side of triangular prism " << (i + 1) << ": ";
        cin >> TriangularHeight >> TriagleSide;
        TriangularPrism[i] = TPrism3(TriangularHeight, TriagleSide);

        cout << "Enter the height and base side of quadrangular prism " << (i + 1) << ": ";
        cin >> QuadrangularHeight >> RectSide;
        QuadrangularPrism[i] = TPrism4(QuadrangularHeight, RectSide);

        double Volume = TriangularPrism[i].Volume() + 5;
        double surfaceArea = QuadrangularPrism[i].Surface();

        sumOfVolumes += Volume;
        sumOfSurfaceAreas += surfaceArea;

    }
    cout << "Sum of volumes of triangular prisms: " << sumOfVolumes << endl;
    cout << "Sum of surface areas of quadrangular prisms: " << sumOfSurfaceAreas << endl;

    return 0;


}
