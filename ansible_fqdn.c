#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <yaml.h>

yaml_parser_t *init() {
  yaml_parser_t *parser = malloc(sizeof(yaml_parser_t));

  assert(yaml_parser_initialize(parser));

  return parser;
}

void parse_doc(yaml_parser_t *parser, char *filename) {

  yaml_document_t *doc = malloc(sizeof(yaml_document_t));

  FILE *file = malloc(sizeof(FILE));
  file = fopen(filename, "rb+");

  yaml_parser_set_input_file(parser, file);

  assert(yaml_parser_load(parser, doc));

  yaml_node_t *node = malloc(sizeof(yaml_node_t));

  int i = 1;
  while (1) {
    node = yaml_document_get_node(doc, i);

    if (node->type == YAML_SCALAR_NODE &&
            (node->data.scalar.value == "tasks") ||
        (node->data.scalar.value == "pre-tasks") ||
        (node->data.scalar.value == "post-tasks")) {
        
        // Do Stuff

    }

    i += 1;
  }
}

int main(int argc, char *argv[]) {
  assert(argc >= 2);

  yaml_parser_t *parser = init();

  parse_doc(parser, argv[1]);

  return EXIT_SUCCESS;
}