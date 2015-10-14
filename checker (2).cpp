#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <dirent.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int mir_count = 11;
const char *mirs [11] = { "hsa-mir-21", "hsa-mir-31", "hsa-mir-34", "hsa-mir-100", "hsa-mir-101", "hsa-mir-125", "hsa-mir-128", "hsa-mir-145", "hsa-mir-141", "hsa-mir-200", "hsa-let-7" };
const int mir_indexes [11] = { 21, 31, 34, 100, 101, 125, 128, 145, 141, 200, 0 };

const float cancer_patient_count  = 484.0f;
const float control_patient_count =  22.0f;

const int cancer_patient  = 484;
const int control_patient =  22;

char dummy [100], dummy1 [100], code_name[100], code_names [900] [20];

int mirna_count = 705, dummy_val;

float value, patient_values [900] [900];

FILE *in, *out;

char *path = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\MicroRNA";

string final_path = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\MicroRNA\\", test;
string final_path2 = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\controlMicroRNA\\";

vector <float> mirna_values [1000];

vector <string> first_group;
vector <string> second_group;

int main()
{
    freopen ("incompatible_groups.txt", "w", stdout);

    DIR*    dir;
    dirent* pdir;

    dir = opendir("C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\MicroRNA");

    int patient_ind = 0;

    while (pdir = readdir(dir))
    {
        if (pdir->d_name [0] == '.')
            continue;

        in = fopen ((final_path + string(pdir->d_name)).c_str(), "r");

        for (int i = 0; i < 4; i++)
            fscanf (in, "%s", &dummy);

        int ind = 0;

        while (fscanf (in, "%s %d %f %s", &code_names [ind], &dummy_val, &value, &dummy) == 4)
        {
            first_group.push_back (string (code_names[ind]));
            ind++;
        }

       // fclose (in);
        patient_ind++;

        break;
    }

    fclose (in);

    dir = opendir("C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\controlMicroRNA");

    while (pdir = readdir(dir))
    {
        if (pdir->d_name [0] == '.')
            continue;

        in = fopen ((final_path2 + string(pdir->d_name)).c_str(), "r");

        for (int i = 0; i < 4; i++)
            fscanf (in, "%s", &dummy);

        int ind = 0;

        while (fscanf (in, "%s %d %f %s", &dummy, &dummy_val, &value, &dummy1) == 4)
        {
            second_group.push_back (string (dummy));
            patient_values [patient_ind] [ind] = value;
            ind++;
        }

        patient_ind++;
        break;
    }


    for (int i = 0; i < second_group.size(); i++)
    {
        bool found(false);
        for (int j = 0; j < first_group.size(); j++)
        {
            if (first_group [j] == second_group [i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout<<second_group [i]<<endl;
        }
    }
    return 0;
}
// Note that you can use GetLastError() to get better error information for the
// W











