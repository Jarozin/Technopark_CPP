#include "args.hpp"
int ParseArguments(int argc, char *argv[], std::string &name_file_name, std::string &title_file_name, std::string &artist_name)
{
    int opt;
    int option_index = 0;
    static struct option long_options[] = {
        {"title-basics-file", 1, 0, 't'},
        {"name-basics-file", 1, 0, 'n'},
        {"help", 0, 0, 'h'},
        {"artist-name", 1, 0, 'a'},
        {0, 0, 0, 0}
    };
     while ((opt = getopt_long_only(argc, argv, "abc", long_options, &option_index)) != -1)
    {
        switch(opt)
        {
            case -1:
                break;
            case 't':
                title_file_name = optarg;
                break;
            case 'n':
                name_file_name = optarg;
                break;
            case 'a':
                artist_name = optarg;
                break;
            case 'h':
                std::cout << "Required arguments: --name-basics-file=filename1 --title-basics-file=filename2 --artist-name=artist_name" << std::endl;
                return 1;
                break;
            default:
                std::cout << "Unknown option given" << std::endl;
                return 1;
        }
    }
    if (title_file_name.empty() || name_file_name.empty() || artist_name.empty())
    {
        std::cout << "Not all arguments were given" << std::endl;
        return 1;
    }
    return 0;
}

