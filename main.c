#include <stdio.h>
#include <stdlib.h>

#include "bmp8.h"
#include "t_bmp8.h"

void print_main_menu() {
    printf("\nPlease choose an option:\n");
    printf("   1. Open an image\n");
    printf("   2. Save an image\n");
    printf("   3. Apply a filter\n");
    printf("   4. Display image information\n");
    printf("   5. Quit\n");
}

void print_filter_menu() {
    printf("\nPlease choose a filter:\n");
    printf("   1. Negative\n");
    printf("   2. Brightness\n");
    printf("   3. Black and white (Threshold)\n");
    printf("   4. Return to the previous menu\n");
}

/* Main function */
int main(void)
{
    t_bmp8 *image = NULL; // Pointer to store the loaded image
    int choice; // User's choice
    int running = 1;

    /* Main application loop */
    while (running) {
        print_main_menu(); // Displays main menu
        scanf("%d", &choice); // Reads the user's choice

        switch (choice) {
            case 1: { // Opens an image
                char filename[100];
                printf("Enter image filename (example: barbara_gray.bmp): ");
                scanf("%s", filename);
                image = bmp8_loadImage(filename);
                if (image != NULL) {
                    printf("Image loaded successfully!\n");
                } else {
                    printf("Failed to load image.\n");
                }
                break;
            }

            case 2: { // Saves an image
                if (image == NULL) {
                    printf("No image loaded!\n");
                    break;
                }
                char save_name[100];
                printf("Enter filename to save (example: result.bmp): ");
                scanf("%s", save_name);
                bmp8_saveImage(save_name, image);
                printf("Image saved successfully!\n");
                break;
            }

            case 3: { // Applies filter
                if (image == NULL) {
                    printf("No image loaded!\n");
                    break;
                }

                int filter_choice;
                print_filter_menu(); // Shows filter choices
                scanf("%d", &filter_choice);

                switch (filter_choice) {
                    case 1: // Applies negative
                        bmp8_negative(image);
                        printf("Negative filter applied.\n");
                        break;

                    case 2: {
                        int value; // Adjusts brightness
                        printf("Enter brightness value (-255 to 255): ");
                        scanf("%d", &value);
                        bmp8_brightness(image, value);
                        printf("Brightness adjusted.\n");
                        break;
                    }

                    case 3: { // Apply threshold
                        int threshold;
                        printf("Enter threshold value (0 to 255): ");
                        scanf("%d", &threshold);
                        bmp8_threshold(image, threshold);
                        printf("Threshold filter applied.\n");
                        break;
                    }

                    case 4: // Return to the previous menu
                        break;

                    default:
                        printf("Invalid filter choice.\n");
                        break;
                }
                break;
            }

            case 4: // Displays image information
                if (image != NULL) {
                    bmp8_printInfo(image);
                } else {
                    printf("No image loaded!\n");
                }
                break;

            case 5: // Quits the application
                running = 0;
                break;

            default:
                printf("The option doesn't exist\n");
                break;
        }
    }

    // Frees the memory before exiting
    if (image != NULL) {
        bmp8_free(image);
    }

    printf("Goodbye.\n");
    return 0;
}