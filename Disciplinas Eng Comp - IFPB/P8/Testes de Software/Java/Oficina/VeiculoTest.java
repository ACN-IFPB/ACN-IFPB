package oficina;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

public class VeiculoTest {
    @Test
    public void testCalculaGarantia() {
        Veiculo veiculo = new Veiculo("ABC-1234", "SUV", 2020);
        assertEquals(2023, veiculo.calculaGarantia());
    }
}
