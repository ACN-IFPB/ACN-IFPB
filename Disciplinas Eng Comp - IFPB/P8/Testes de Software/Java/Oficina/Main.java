package oficina;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Mecanico mecanico = new Mecanico("1234", "João", Arrays.asList("Injeção", "Elétrica", "Freios"));
        Veiculo veiculo = new Veiculo("ABC-1234", "SUV", 2020);
        Servico servico = new Servico(1, "Troca de óleo", mecanico, veiculo);

        System.out.println("Mecânico especialista: " + mecanico.funcionarioEspecialista());
        System.out.println("Garantia do veículo expira em: " + veiculo.calculaGarantia());

        servico.ordemServico("Revisão completa");
        System.out.println("Número de ocorrências do veículo: " + veiculo.getNumOcorrencias());
    }
}
