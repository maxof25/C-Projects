#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int number_of_people(FILE *fp){
    int size = 0;
    char buff[1024];
    if(fp!=NULL){
        while(fgets(buff,80,fp)!=NULL){
            size = size + 1;
        }
    }
    rewind(fp);
    return size;
    /*The function above creates a while loop that copies each line of the file stream to the character array 'buff'.
    After each line is copied to the array, the integer variable 'size' is incremented in conjunction to the number of lines contained within the array.
    This will count how many people there are as each person, alongside its respective data, takes up 1 line of the txt file.*/

}
int number_of_nice_people(FILE *fp){
    int itemCount = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    /*The variables above will be used in the loops below. Such contains the character array 'buff', 3 integer variables to count each individual item that is classified as
    a "nice person", each row of the file and finally the number of individual items in the CSV (seperated by commas).*/
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        //This strtok() function breaks the contents stored in the 'buff' variable, and divides it along its commas, storing each individual item within the character array 'field'. 
        while(field!=NULL){
            //This ensures that the contents of the array are not empty.
            if(field_count == 2){
                double d;
                int vl = atoi(field);
                /*As seen in the example line, the number that connotes the point at which the 'behaviour score' is stored at is 2, in turn storing the contents in the integer
                variable after parsing it from the initial string*/
                if(vl>=10){
                    itemCount++;
                    //The variable will increment if the value of their 'behaviourscore' is more than or equal to +10.
                }
            }
            field = strtok(NULL, ",");
            field_count++;
            //This moves it to the next field after each loop.
        }
         i++;
    }
    rewind(fp);
    //This sets the file position indicator for the stream pointed to by stream to the beginning of the file.
    return itemCount;
    //Finally returns the amount of people with a behaviour score =>10.
}
int number_of_naughty_people(FILE *fp){
    int itemCount = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 2){
                int vl = atoi(field);
                if(vl<=(-10)){
                    itemCount++;
                }
            }
            field = strtok(NULL, ",");
            field_count++;
        }
         i++;
    }
    rewind(fp);
    return itemCount;
    //This function does the same as the number_of_nice_people() function, however it increments the variable itemCount if the 'behaviour score' is <=-10.
}
float average_behaviourscore(FILE *fp){
    int itemCount = 0;
    double total = 0;
    float average = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 2){
                itemCount++;
                int vl = atoi(field);
                total = total + vl;
                //Similarly to the above functions, this recieves the individual bahviour scores, parses it to an in and thus adds it to the double variable 'total'.
            }
            field = strtok(NULL, ",");
            field_count++;
        }
         i++;
    }
    rewind(fp);
    average = total/itemCount;
    return average;
    //The above 2 lines calculates the average, for which is stored in the float variable 'average' and is subsequently returned to main(). 
}
void naughtiest_person(FILE *fp, double lat, double lng){
    int lowest=0;
    int temp2=0;
    int lowestRow = 0;
    char buff[1024];
    int row_count = 0;
    int field_count = 0;
    int i = 0;
    int itemCount = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 2){
                itemCount++;                
                if(itemCount==1){
                    lowest = atoi(field);
                }
                if(itemCount>=2){
                    temp2 = atoi(field);
                }
                if(temp2<lowest&&itemCount!=1){
                    lowest = temp2;
                    lowestRow = row_count;
                }
            }
            //The if statement above, finds the lowest scoring behaviour score, to which it stores its row count in the row_count variable.
            if(field_count==3 && row_count == lowestRow){
                double d;
                sscanf(field, "%lf", &d);
                lat = d;
                //This will retrieve the latitude for the lowest scoring behaviour score.
            }
            if(field_count==4 && row_count == lowestRow){
                double e;
                sscanf(field, "%lf", &e);
                lng = e;
                //This will retrieve the longitude for the lowest scorer.
            }
            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }
    rewind(fp);  
    printf("%f, ", lat);
    printf("%f.\n", lng);
    //This will print both the latitude followed by the longitude to the terminal of the lowest behaviour scorer.
}
    
float total_weight(FILE *fp){
    float total = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 5){
                float val2 = atof(field);
                total = total + val2;
                /*This repeats the calculations as of the function average_behaviourscore(), but at the address of the variables connoting the weight.
                The values are parsed to the float 'val2' and then added to the float 'total'*/
            }
            field = strtok(NULL, ",");
            field_count++;
        }
         i++;
    }
    rewind(fp);
    return total;
    //The total is returned.
}
int calculate_sleighs_needed(FILE *fp){
    int sleighsNeeded = 0;
    float total = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 5){
                float val2 = atof(field);
                total = total + val2;
                //This is identical to the function prior, for which finds the total weight of each gift.
            }
            field = strtok(NULL, ",");
            field_count++;
        }
         i++;
    }
    rewind(fp);
    sleighsNeeded = (total/1500)+1;
    //This differs to the prior function as it divides it along the weight of 1500KG, for which 1 sleigh has the ability to carry.
    return sleighsNeeded;
}
int calculate_time_needed(FILE *fp){
    int timeNeeded = 0;
    int sleighsNeeded = 0;
    float total = 0;
    int row_count = 0;
    int field_count = 0;
    char buff[1024];
    int i = 0;
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count == 5){
                float val2 = atof(field);
                total = total + val2;
            }
            field = strtok(NULL, ",");
            field_count++;
        }
         i++;
    }
    rewind(fp);
    sleighsNeeded = total/1500;
    timeNeeded = (sleighsNeeded*1.5)+1;
    /*This is an identical function to the prior, however, it multiplies the total by 1.5 (which equates to 90 seconds when converted to minutes).  
    This thus allows it to determine the time taken to deliver all packages in relation to minutes*/
    return timeNeeded;
}
void largest_gathering(FILE *fp, double lng, double lat){
    int tempLat=0;
    int tempLng=0;
    char buff[1024];
    int row_count = 0;
    int field_count = 0;
    int i = 0;
    int itemCount = 0;
    int size = number_of_people(fp);
    double arrayLat[size]; 
    double arrayLng[size];
    while(fgets(buff, 100, fp)){
        field_count = 0;
        row_count++;
        char *field = strtok(buff, ",");
        while(field!=NULL){
            if(field_count==3){
                double d;
                sscanf(field, "%lf", &d);
                arrayLat[i] = d;
            }
            if(field_count==4){
                double e;
                sscanf(field, "%lf", &e);
                arrayLng[i] = e;
            }
            field = strtok(NULL, ",");
            field_count++;
        }
        i++;
    }
    //The while loop above will store the individual longitudes and latitudes of each of the peoples' locations.
    rewind(fp);
    int count = 1, tempCount;
    double temp = 0;
    lat = arrayLat[0];
    for(int i = 0; i < (size - 1); i++){
        temp = arrayLat[i];
        tempCount = 0;
        for (int j = 1; j < size; j++){
            if(temp==arrayLat[j]){
                tempCount++;
            }
            if(tempCount>count){
                lat = temp;
                count = tempCount;
            }
        }
    }
    int count2 = 1, tempCount2;
    double temp2 = 0;
    lng = arrayLng[0];
    for(int i = 0; i < (size - 1); i++){
        temp2 = arrayLng[i];
        tempCount2 = 0;
        for (int j = 1; j < size; j++){
            if(temp2==arrayLng[j]){
                tempCount2++;
            }
            if(tempCount2>count2){
                lng = temp2;
                count2 = tempCount2;
            }
        }
    }
    //The above 4 For loops will sort the arrays to store the largest value in the variables lng and lat.
    printf("%f, ", lat);
    printf("%f.\n", lng);
    //The largest latitiude and longitude are returned to the main function.


}
int main()
{
    FILE *fp;
    fp = fopen("santaslist.txt", "r");
    printf("There are %d people on the list.\n", number_of_people(fp));
    printf("%d of them are nice.\n", number_of_nice_people(fp));
    printf("%d of them are naughty.\n", number_of_naughty_people(fp));
    printf("The average behaviourscore is %f.\n", average_behaviourscore(fp));
    double lat;
    double lng;
    printf("The naughtiest person is located at ");
    naughtiest_person(fp,lat,lng);   
    printf("The total weight is %f KG.\n", total_weight(fp));
    printf("%d sleighs will be needed.\n", calculate_sleighs_needed(fp));
    printf("This will take %d minutes.\n", calculate_time_needed(fp));
    printf("The largest gathering will be at ");
    largest_gathering(fp,lat,lng);
    fclose(fp);
}