#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{

    //check command line argument 
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }

    //open memory card
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *img = NULL;

    //create a buffer - read 512 bytes into buffer
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    //create counter
    int file_counter = 0; 

    //create jpeg counter 
    int jpeg_counter = 0;
    
    //create filename and place to store filename
    char filename[100];

    //repeat until end of card
    while (fread(buffer, sizeof(buffer), 1, raw_file))
    {
        //if header is the same
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if JPEG does not equal zero, close
            //mark first JPEG
            if (jpeg_counter != 0)
            {          
                fclose(img);
            }

            else
            {
                jpeg_counter = 1;
            }

            sprintf(filename, "%03i.jpg", file_counter);
            file_counter ++;
            img = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, img);

        }

        else
        {
            //if already found JPEG
            if (jpeg_counter == 1)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }

    }

    //close files
    fclose(raw_file);
    fclose(img);

}