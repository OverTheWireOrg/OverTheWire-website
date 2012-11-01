/* gcc -fno-pie -fno-stack-protector */

int main(int argc, char **argv)
{
	char buffer[64];
	gets(buffer);
}
