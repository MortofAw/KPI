#include <time.h>

#include "measurement.h"
#include "vector_filling.h"
#include "vector_sorting.h" 
#include "3D_filling.h"
#include "3D_sorting.h"

clock_t Res[measurements_number];

// функція обробки і усереднення значень вимірів часу роботи алгоритма
float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;
    clock_t buf;
	int L = rejected_number; 
	int R = measurements_number - 1;
	int k = rejected_number;
	
	for (int j = 0; j < min_max_number; j++) {
		for (int i = L; i < R; i++)	{
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}

		R = k;
		
		for (int i = R - 1; i >= L; i--) {
			if (Res[i] > Res[i + 1]) {
				buf = Res[i];
				Res[i] = Res[i + 1];
				Res[i + 1] = buf;
				k = i;
			}
		}
	
		L = k + 1;
	}

    Sum=0;
    
	for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
       Sum = Sum + Res[i];
    
	AverageValue = (float)Sum / (float)(measurements_number - 2 * min_max_number - rejected_number);

    return AverageValue;
}

//заповнення масиву вимірів часу (Select2	(Alg1), 3D-масив)
void Select2_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
        for (int i = 0; i < measurements_number; i++)
        {
           	ordered3DFill();
			Res[i] = Select2();
	    }
	}
    else if (fillMethod == 'r')
    {
       	for (int i = 0; i < measurements_number; i++)
        {
			random3DFill();
            Res[i] = Select2();
        }
    }
    else if (fillMethod == 'b')
    {
		for (int i = 0; i < measurements_number; i++)
        {
			backOrdered3DFill();
            Res[i] = Select2();
        }	
    }
}

//заповнення масиву вимірів часу (Select7	(Alg2), 3D-масив)
void Select7_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
		for (int i = 0; i < measurements_number; i++)
        {
			ordered3DFill();
            Res[i] = Select7();
        }
    }
    else if (fillMethod == 'r')
    {
		for (int i = 0; i < measurements_number; i++)
		{
		   random3DFill();
		   Res[i] = Select7();
		}	
    }
    else if (fillMethod == 'b')
    {
		for (int i = 0; i < measurements_number; i++)
        {
			backOrdered3DFill();
            Res[i] = Select7();
        }	
    }
}

//заповнення масиву вимірів часу (EfillMethodchange2 	(Alg3), 3D-масив)
void Exchange2_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
		for (int i = 0; i < measurements_number; i++)
        {
			ordered3DFill();
            Res[i] = Exchange2();
        }	
    }
    else if (fillMethod == 'r')
    {
		for (int i = 0; i < measurements_number; i++)
        {
            
			random3DFill();
			Res[i] = Exchange2();
        }	
    }
    else if (fillMethod == 'b')
    {
        
		for (int i = 0; i < measurements_number; i++)
        {
			backOrdered3DFill();
			Res[i] = Exchange2();
        }	
    }
}

//заповнення масиву вимірів часу (Select2	(Alg1), вектор)
void select2_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
        for (int i = 0; i < measurements_number; i++)
        {
            orderedVecFill();
            Res[i] = select2();
        }
    }
    else if (fillMethod == 'r')
    {
        for (int i = 0; i < measurements_number; i++)
        {
            randomVecFill();
            Res[i] = select2();
        }
    }
    else if (fillMethod == 'b')
    {
        for (int i = 0; i < measurements_number; i++)
        {
			backOrderedVecFill();
            Res[i] = select2();
        }
    }
}

//заповнення масиву вимірів часу (Select7	(Alg2), вектор)
void select7_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
        for (int i = 0; i < measurements_number; i++)
        {
			orderedVecFill();
            Res[i] = select7();
        }
    }
    else if (fillMethod == 'r')
    {
        for (int i = 0; i < measurements_number; i++)
        {
			randomVecFill();
            Res[i] = select7();
        }
    }
    else if (fillMethod == 'b')
    {
        for (int i = 0; i < measurements_number; i++)
        {
			backOrderedVecFill();
            Res[i] = select7();
        }
    }
}

//заповнення масиву вимірів часу (EfillMethodchange2		(Alg3), вектор)
void exchange2_measurement (char fillMethod)
{
    if (fillMethod == 'o')
    {
         for (int i = 0; i < measurements_number; i++)
         {
         	orderedVecFill();
			Res[i] = exchange2();
		 }
    }
    else if (fillMethod == 'r')
    {
        for (int i = 0; i < measurements_number; i++)
        {
			randomVecFill();
			Res[i] = exchange2();
        }
    }
    else if (fillMethod == 'b')
    {
       for (int i = 0; i < measurements_number; i++)
       {
		   backOrderedVecFill();
           Res[i] = exchange2();
       }
    }
}
