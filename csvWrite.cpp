#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair

template<class T>
void write_csv(std::string filename, std::vector<std::vector<T>> dataset)
{
// Make a CSV file with one or more columns of integer values
// The dataset is represented as a vector of these columns
// Note that all columns should be the same size

// Create an output filestream object
    std::ofstream myFile(filename);

    // Send data to the stream
    for (int i = 0; i < dataset.at(0).size(); ++i)
    {
        for (int j = 0; j < dataset.size(); ++j)
        {
            myFile << dataset.at(j).at(i);
            if (j != dataset.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }

    // Close the file
    myFile.close();
}

int main()
{
// Make three vectors, each of length 100 filled with 1s, 2s, and 3s
    std::vector<int> vec1(100, 1);
    std::vector<int> vec2(100, 2);
    std::vector<int> vec3(100, 3);

    // Wrap into a vector
    std::vector<std::vector<int>> vals = { vec1, vec2, vec3 };

    // Write the vector to CSV
    write_csv("/home/pi/workspace/1.Ansur_SOEM_Controller/log/three_cols.csv", vals);

    return 0;
}