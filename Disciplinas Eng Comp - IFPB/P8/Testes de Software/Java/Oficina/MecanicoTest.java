package oficina;

import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;
import java.util.Arrays;

public class MecanicoTest {
    @Test
    public void testFuncionarioEspecialista() {
        Mecanico mecanico = new Mecanico("1234", "João", Arrays.asList("Injeção", "Elétrica", "Freios"));
        assertTrue(mecanico.funcionarioEspecialista());
    }
}
