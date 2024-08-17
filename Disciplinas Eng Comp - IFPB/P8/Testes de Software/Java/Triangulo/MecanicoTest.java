public class MecanicoTest {
    @Test
    public void testFuncionarioPremium() {
        List<String> especialidades = new ArrayList<>();
        especialidades.add("Mecânica");
        especialidades.add("Elétrica");
        especialidades.add("Pintura");

        Mecanico mecanico = new Mecanico("123", "João", especialidades);

        assertTrue(mecanico.funcionarioPremium());
    }
}

