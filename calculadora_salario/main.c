#include <stdio.h>

// Função para calcular o desconto do INSS
float calcular_inss(float salario_bruto) {
    if (salario_bruto <= 1212) {
        return salario_bruto * 0.075;  // 7.5%
    } else if (salario_bruto <= 2427.35) {
        return salario_bruto * 0.09;   // 9%
    } else if (salario_bruto <= 3641.03) {
        return salario_bruto * 0.12;   // 12%
    } else if (salario_bruto <= 7087.22) {
        return salario_bruto * 0.14;   // 14%
    } else {
        return 7087.22 * 0.14;        // Teto do INSS
    }
}

// Função para calcular o desconto do Imposto de Renda (IR)
float calcular_ir(float salario_bruto) {
    if (salario_bruto <= 1903.98) {
        return 0;
    } else if (salario_bruto <= 2826.65) {
        return salario_bruto * 0.075 - 142.80;   // 7.5% com desconto
    } else if (salario_bruto <= 3751.05) {
        return salario_bruto * 0.15 - 354.80;    // 15% com desconto
    } else if (salario_bruto <= 4664.68) {
        return salario_bruto * 0.225 - 636.13;   // 22.5% com desconto
    } else {
        return salario_bruto * 0.275 - 869.36;   // 27.5% com desconto
    }
}

// Função para calcular o salário líquido
float calcular_salario_liquido(float salario_bruto, float vale_alimentacao) {
    float inss = calcular_inss(salario_bruto);
    float ir = calcular_ir(salario_bruto);
    return salario_bruto - inss - ir - vale_alimentacao;
}

int main() {
    float salario_bruto, vale_alimentacao;

    // Entrada de dados
    printf("Digite o salario bruto: R$ ");
    scanf("%f", &salario_bruto);

    printf("Digite o valor do desconto do vale-alimentacao: R$ ");
    scanf("%f", &vale_alimentacao);

    // Cálculos
    float inss = calcular_inss(salario_bruto);
    float ir = calcular_ir(salario_bruto);
    float salario_liquido = calcular_salario_liquido(salario_bruto, vale_alimentacao);

    // Resultado
    printf("\nSalario Bruto: R$ %.2f\n", salario_bruto);
    printf("Desconto INSS: R$ %.2f\n", inss);
    printf("Desconto Imposto de Renda: R$ %.2f\n", ir);
    printf("Desconto Vale-Alimentacao: R$ %.2f\n", vale_alimentacao);
    printf("Salario Liquido: R$ %.2f\n", salario_liquido);

    return 0;
}
