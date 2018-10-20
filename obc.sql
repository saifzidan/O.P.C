create proc storage_insert
@left_motor float , @right_motor float , @ultrasonic float , @time datetime
as
begin
insert into storage 
values (@left_motor,@right_motor,@ultrasonic,@time)
end
create proc storage_update
@left_motor float , @right_motor float , @ultrasonic float , @time datetime , @id int
as
begin
update storage
set
left_motor = @left_motor,
right_motor = @right_motor,
ultrasonic = @ultrasonic,
[time] = @time
where
id = @id
end
create proc storage_one_delete
@id int
as
begin
delete from storage
where
id = @id
end
create proc storage_delete
as
begin
delete from storage
end
create proc storage_one_select
@id int
as
begin
select * from storage
where
id = @id
end
create proc storage_select
as
begin
select * from storage
end
