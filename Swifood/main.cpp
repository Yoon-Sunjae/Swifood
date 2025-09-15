#include "error.hpp"
#include "swifood.hpp"


SwifoodLibrary* g_swifood;
std::string g_currentFileName;


int main(int argc, char* argv[])
{
    g_swifood = new SwifoodLibrary();

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <recipename>" << std::endl;
        return 1;
    }

    g_swifood->load("actions.swifd");
    g_swifood->load("ingredients.swifd");
    g_swifood->load("recipes.swifd");

    Recipe recipe(g_swifood->recipeManager.get_definition(argv[1]));    

    if (ErrorHandler::get_instance().is_error_exist()) {
        ErrorHandler::get_instance().print_errors();
    } else {
        recipe.print();
    }


    return 0;
}
