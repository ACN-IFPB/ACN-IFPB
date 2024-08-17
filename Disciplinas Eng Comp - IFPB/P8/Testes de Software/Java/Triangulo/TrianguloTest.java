
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TrianguloTest {

    @Test
    public void testTrianguloEscalenoValido() {
        Triangulo triangulo = new Triangulo(3, 4, 5);
        assertEquals("Escaleno", triangulo.classificar());
    }

    @Test
    public void testTrianguloIsoscelesValido() {
        Triangulo triangulo = new Triangulo(4, 4, 5);
        assertEquals("Isósceles", triangulo.classificar());
    }

    @Test
    public void testTrianguloEquilateroValido() {
        Triangulo triangulo = new Triangulo(5, 5, 5);
        assertEquals("Equilátero", triangulo.classificar());
    }

    @Test
    public void testLadoZero() {
        Triangulo triangulo = new Triangulo(0, 4, 5);
        assertEquals("Não é um triângulo válido", triangulo.classificar());
    }

    @Test
    public void testLadoNegativo() {
        Triangulo triangulo = new Triangulo(-3, 4, 5);
        assertEquals("Não é um triângulo válido", triangulo.classificar());
    }

    @Test
    public void testSomaDoisLadosIgualTerceiro() {
        Triangulo triangulo = new Triangulo(3, 4, 7);
        assertEquals("Não é um triângulo válido", triangulo.classificar());
    }

    @Test
    void testEhEquilatero() {
        Triangulo triangulo = new Triangulo(3, 3, 3);
        assertTrue(triangulo.ehEquilatero());
    }

    @Test
    void testEhIsosceles() {
        Triangulo triangulo = new Triangulo(3, 3, 4);
        assertTrue(triangulo.ehIsosceles());
    }

    @Test
    void testEhEscaleno() {
        Triangulo triangulo = new Triangulo(3, 4, 5);
        assertTrue(triangulo.ehEscaleno());
    }

    @Test
    void testCalculaPerimetro() {
        Triangulo triangulo = new Triangulo(3, 4, 5);
        assertEquals(12, triangulo.calculaPerimetro());
    }
}