#include <stdio.h>
#include <string.h>

struct designData {
    int numDesigns;
    float data[4];
};

int write_to_file(int designNum, double data) {
    FILE *file;
    char fileName[12];
    sprintf(fileName, "design%d.txt", designNum);
    if ((file = fopen(fileName, "w")) == NULL) {
        printf("Cannot open file for reading.");
        return -1;
    }
    fprintf(file, "Input script for design %d\n", designNum);
    fprintf(file, "Length of strut is %.1f mm", data);
    if (fclose(file) != 0) {
        printf("Cannot close file.");
        return -1;
    }
    return 0;
}

struct designData read_from_file(void) {
    FILE *file;
    struct designData desData;
    if ((file = fopen("designData.txt", "r")) == NULL) {
        printf("Cannot open file for reading.");
    }
    fscanf(file, "%d %f %f %f", &desData.numDesigns, desData.data,
           desData.data + 1, desData.data + 2);
    if (fclose(file) != 0) {
        printf("Cannot close file.");
    }
    return desData;
}

int main(void) {
    int i, numPts;
    struct designData desData;
    desData = read_from_file();
    numPts = desData.numDesigns;
    for (i = 0; i < numPts; i++) {
        write_to_file(i + 1, desData.data[i]);
    }
    return 0;
}