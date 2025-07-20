// include/ort_wrapper.h
#ifndef ORT_WRAPPER_H
#define ORT_WRAPPER_H

#include <stdbool.h>

// Inicializa o ONNX Runtime (ambiente global, opções, etc.)
bool ort_initialize();

// Carrega um modelo ONNX a partir do caminho informado
bool ort_load_model(const char* model_path);

// Libera todos os recursos alocados
void ort_cleanup();

#endif // ORT_WRAPPER_H
