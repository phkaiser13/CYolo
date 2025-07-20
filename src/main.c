// src/main.c
#include <stdio.h>
#include "ort_wrapper.h"

int main() {
    if (!ort_initialize()) {
        fprintf(stderr, "Erro ao inicializar o ONNX Runtime\n");
        return 1;
    }

    if (!ort_load_model("yolov5n.onnx")) {
        fprintf(stderr, "Erro ao carregar o modelo YOLOv5n\n");
        return 1;
    }

    printf("Modelo carregado com sucesso!\n");

    ort_cleanup();
    return 0;
}
