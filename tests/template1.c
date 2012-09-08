#include <stdio.h>
#include <nsstemplate.h>

#define templatefile	"./samples/template1.chtml"
#define title			"SAMPLE1"
#define heading			"This is a sample."

int main(int argc, char *argv[]) {
	template_context_t tpl;
	continue_t deadyet = !(template_init(&tpl, getenv("PWD"), templatefile));
	if (deadyet) { printf("We're dead.\n"); } else { printf("Not dead yet!\n"); }

	template_execute(&tpl, stdout);

	template_finish(&tpl);

	return 0;
}