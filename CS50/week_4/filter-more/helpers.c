#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE avg =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE out[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgBlue = image[i][j].rgbtBlue;
            int avgGreen = image[i][j].rgbtGreen;
            int avgRed = image[i][j].rgbtRed;

            float nPixels = 1.0;

            if (i > 0)
            {
                nPixels++;
                avgBlue += image[i - 1][j].rgbtBlue;
                avgGreen += image[i - 1][j].rgbtGreen;
                avgRed += image[i - 1][j].rgbtRed;
            }
            if (i > 0 && j > 0)
            {
                nPixels++;
                avgBlue += image[i - 1][j - 1].rgbtBlue;
                avgGreen += image[i - 1][j - 1].rgbtGreen;
                avgRed += image[i - 1][j - 1].rgbtRed;
            }
            if (j > 0)
            {
                nPixels++;
                avgBlue += image[i][j - 1].rgbtBlue;
                avgGreen += image[i][j - 1].rgbtGreen;
                avgRed += image[i][j - 1].rgbtRed;
            }
            if (i < height - 1 && j > 0)
            {
                nPixels++;
                avgBlue += image[i + 1][j - 1].rgbtBlue;
                avgGreen += image[i + 1][j - 1].rgbtGreen;
                avgRed += image[i + 1][j - 1].rgbtRed;
            }
            if (i < height - 1)
            {
                nPixels++;
                avgBlue += image[i + 1][j].rgbtBlue;
                avgGreen += image[i + 1][j].rgbtGreen;
                avgRed += image[i + 1][j].rgbtRed;
            }
            if (i < height - 1 && j < width - 1)
            {
                nPixels++;
                avgBlue += image[i + 1][j + 1].rgbtBlue;
                avgGreen += image[i + 1][j + 1].rgbtGreen;
                avgRed += image[i + 1][j + 1].rgbtRed;
            }
            if (j < width - 1)
            {
                nPixels++;
                avgBlue += image[i][j + 1].rgbtBlue;
                avgGreen += image[i][j + 1].rgbtGreen;
                avgRed += image[i][j + 1].rgbtRed;
            }
            if (i > 0 && j < width - 1)
            {
                nPixels++;
                avgBlue += image[i - 1][j + 1].rgbtBlue;
                avgGreen += image[i - 1][j + 1].rgbtGreen;
                avgRed += image[i - 1][j + 1].rgbtRed;
            }

            out[i][j].rgbtBlue = round(avgBlue / nPixels);
            out[i][j].rgbtRed = round(avgRed / nPixels);
            out[i][j].rgbtGreen = round(avgGreen / nPixels);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = out[i][j];
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE out[height][width];

    const int kernel_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    const int kernel_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxBlue = 0;
            int GxGreen = 0;
            int GxRed = 0;

            int GyBlue = 0;
            int GyGreen = 0;
            int GyRed = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!(i - k < 0 || i - k >= height || j - l < 0 || j - l >= width))
                    {
                        int valx = kernel_x[k + 1][l + 1];
                        int valy = kernel_y[k + 1][l + 1];

                        GxRed += image[i - k][j - l].rgbtRed * valx;
                        GxGreen += image[i - k][j - l].rgbtGreen * valx;
                        GxBlue += image[i - k][j - l].rgbtBlue * valx;

                        GyRed += image[i - k][j - l].rgbtRed * valy;
                        GyGreen += image[i - k][j - l].rgbtGreen * valy;
                        GyBlue += image[i - k][j - l].rgbtBlue * valy;
                    }
                }
            }

            int red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
            int green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            int blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));

            red = (red > 255) ? 255 : red;
            green = (green > 255) ? 255 : green;
            blue = (blue > 255) ? 255 : blue;

            out[i][j].rgbtBlue = blue;
            out[i][j].rgbtRed = red;
            out[i][j].rgbtGreen = green;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = out[i][j];
        }
    }
}
