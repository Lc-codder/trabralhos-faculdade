use bd_AgendaNPJ;
alter table assistido
add logradouro varchar(100) null,
add numero_logradouro varchar(100) null,
add cep char(8) null,
add bairro varchar(100) null,
drop column endereço,
modify column identidade varchar(30) null;

alter table agendamento
modify column data_agendamento datetime not null default current_timestamp;
insert into agendamento (data_agendamento = null);