use bd_aluno;
select * from Curso;

INSERT INTO Curso (curso) values
('medicina'),
('engenharia civil'),
('direito'),
('arquitetura'),
('ciencia dacompitaçao'),
('analise de sistemas'),
('enegenharia de computaçao');

insert into Curso (curso) values ('engenharia de computaçao');

select * from curso order by idCurso;

select * from grauinstrucao;

insert into GrauInstrucao (grauInstrucao)
values
('ensino fundamental'),
('ensino medio'),
('graduação'),
('especialização'),
('mestrado'),
('doutorado');

select * from grauInstrucao order by idGrauInstrucao;


