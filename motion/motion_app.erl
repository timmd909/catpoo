-module(motion_app).

-behavior(application).

-export([start/2, stop/1]).

% -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=-

start(_Host, _Args) ->
	erlang:display_nl("Starting motion application"),
	ThriftPort = 11234,
	thrift_server:start_link(ThriftPort, catPooMotion_thrift, ?MODULE),
	ok.

stop(_) ->
	erlang:display_nl("Stopping motion application"),
	thrift_socket_server:stop(Host),
	ok.

% -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=- -=-

handle_function(Function, Args) when is_atom(Function), is_tuple(Args) ->
	case apply(motion, Function, tuple_to_list(Args)) of 
		ok -> ok;
		Reply -> {reply, Reply}
	end.

handle_error(_A, Reason) ->
	case Reason of 
		closed ->
			% normal exit
			ok;
%		SomethingElse ->
%			% died a horrible death! 
%			handle error some way here in the future  
	end.
