import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class LivroTest {

    @Test
    void testGetNome() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        assertEquals("Meu Livro", livro.getNome());
    }

    @Test
    void testSetNome() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        livro.setNome("Novo Nome");
        assertEquals("Novo Nome", livro.getNome());
    }

    @Test
    void testGetEdicao() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        assertEquals(2022, livro.getEdicao());
    }

    @Test
    void testSetEdicao() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        livro.setEdicao(2025);
        assertEquals(2025, livro.getEdicao());
    }

    @Test
    void testGetAutor() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        assertEquals("Eu Mesmo", livro.getAutor());
    }

    @Test
    void testSetAutor() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        livro.setAutor("Novo Autor");
        assertEquals("Novo Autor", livro.getAutor());
    }

    @Test
    void testGetIsbn() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        assertEquals("1234567890", livro.getIsbn());
    }

    @Test
    void testSetIsbn() {
        Livro livro = new Livro("Meu Livro", 2022, "Eu Mesmo", "1234567890");
        livro.setIsbn("9876543210");
        assertEquals("9876543210", livro.getIsbn());
    }

    @Test
    void testVerificaLancamento_True() {
        Livro livro = new Livro("Meu Livro", 2025, "Eu Mesmo", "1234567890");
        assertTrue(livro.verificaLancamento());
    }

    @Test
    void testVerificaLancamento_False() {
        Livro livro = new Livro("Meu Livro", 2020, "Eu Mesmo", "1234567890");
        assertFalse(livro.verificaLancamento());
    }
}