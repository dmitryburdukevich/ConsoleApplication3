#include "stdafx.h"
#include <windows.h>
#include <iostream>

void title()
{
	system("cls");
	puts("###  # #  ###  ###  ###  #   #  ###  ###  #  #  ###  ###");
	puts("#    # #  # #  #    # #  ## ##  # #  # #  # #   #     # ");
	puts("###  # #  ###  ###  ###  # # #  ###  ###  ##    ###   # ");
	puts("  #  # #  #    #    ##   #   #  # #  ##   # #   #     # ");
	puts("###  ###  #    ###  # #  #   #  # #  # #  #  #  ###   # ");
	puts(" ");
	puts("#####");
	puts("    #################################");
	puts("     #|   |   |   |   |   |   |   |#");
	puts("     #|___|___|___|___|___|___|___#");
	puts("      #   |   |   |   |   |   |  #");
	puts("      #___|___|___|___|___|___|_#");
	puts("       #  |   |   |   |   |   |#");
	puts("       ########################");
	puts("       #");
	puts("       #");
	puts("       ########################");
	puts("        ###                ###");
	puts("         #                  #");
	Sleep(1500);
	return;
}

void menu()
{
		puts("\n");
		puts("����:");
		puts("\t1. �������");
		puts("\t2. ����������� ������");
		puts("\t3. ����������� ������� �������");
		puts("\t4. �������");
		puts("\t5. �����");
}

void about()
{
	puts("\n��������� ��� ������ � �������� ��������� ������������.\n���� ��������� �������.\n���������� ������ ������.");
}