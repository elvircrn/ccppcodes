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
const char *mirs [mir_count] = { "hsa-mir-21", "hsa-mir-31", "hsa-mir-34", "hsa-mir-100", "hsa-mir-101", "hsa-mir-125-b", "hsa-mir-128", "hsa-mir-145", "hsa-mir-141", "hsa-mir-200", "let-7family" };
const int mir_indexes [11] = { 21, 31, 34, 100, 101, 125, 128, 145, 141, 200, 0 };

const float cancer_patient_count  = 484.0f;
const float control_patient_count =  22.0f;

const int cancer_patient  = 484;
const int control_patient =  22;

char dummy [100], code_name[100], code_names [900] [20];

int mirna_count = 705, dummy_val;

float value, patient_values [900] [900];

FILE *in, *out;

char *path = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\MicroRNA";

string final_path = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\MicroRNA\\", test;
string final_path2 = "C:\\Users\\Inspiron\\Desktop\\codes\\vracanje u formu lol\\Prof Senol\\controlMicroRNA\\";

vector <float> mirna_values [1000];

int main()
{
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
            patient_values [patient_ind] [ind] = value;
            ind++;
        }

       // fclose (in);
        patient_ind++;
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

        while (fscanf (in, "%s %d %f %s", &code_names [ind], &dummy_val, &value, &dummy) == 4)
        {
            patient_values [patient_ind] [ind] = value;
            ind++;
        }

        patient_ind++;
    }


    out = fopen ("out1.txt", "w");

    fprintf (out, "%s;", "miRNA_ID");

    for (int i = 1; i <= cancer_patient; i++)
        fprintf (out, "%d;", i);

    fprintf (out, "average;");

    for (int i = 1; i <= control_patient; i++)
        fprintf (out, "%d;", i); fprintf (out, "average;\n");

    for (int i = 0; i < mirna_count; i++)
    {
        float average = 0.0f;
        fprintf (out, "%s;", code_names [i]);
        /*for (int j = 0; j < mirna_count; j++)
        {
            if (strcmp (mirs [j], ))
        }*/
        for (int j = 0; j < cancer_patient; j++)
        {
            fprintf (out, "%f;", patient_values [j] [i]);
            average += (patient_values [j] [i] / cancer_patient_count);
        }

        fprintf (out, "%f;", average);

        average = 0.0f;

        for (int j = cancer_patient; j < cancer_patient + control_patient; j++)
        {
            fprintf (out, "%f;", patient_values [j] [i]);
            average += (patient_values [j] [i] / control_patient_count);
        }

        fprintf (out, "%f;\n", average);
    }


    fclose (out);
    return 0;
}
// Note that you can use GetLastError() to get better error information for the
// W











