package oficina;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;
import java.util.Arrays;

public class ServicoTest {
    @Test
    public void testOrdemServico() {
        Mecanico mecanico = new Mecanico("1234", "João", Arrays.asList("Injeção", "Elétrica"));
        Veiculo veiculo = new Veiculo("ABC-1234", "SUV", 2020);
        Servico servico = new Servico(1, "Troca de óleo", mecanico, veiculo);

        servico.ordemServico("Revisão completa");
        assertEquals(1, veiculo.getNumOcorrencias());
    }
}
