#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &cpy) {
    this->target = cpy.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
    std::ofstream file((this->target + "_shrubbery").c_str());

    file << "              _{\\ _{\\{\\/}/}/}__\n"
            "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
            "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
            "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
            "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
            "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
            "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
            "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
            "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
            "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
            "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
            "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
            "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
            "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
            "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
            "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
            "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
            "              {){/ {\\/}{\\/} \\}\\}\n"
            "              (_)  \\.-'.-/\n"
            "          __...--- |'-.-'| --...__\n"
            "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
            " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
            " .  '-  '    .--'  | '-.'|    .  '  . '\n"
            "          ' ..     |'-_.-|\n"
            "  .  '  .       _.-|-._ -|-._  .  '  .\n"
            "              .'   |'- .-|   '.\n"
            "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
            "   .-' '        '-._______.-'     '  .\n"
            "        .      ~,\n"
            "    .       .   |\\   .    ' '-.\n" << std::endl;
    file.close();
    
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}