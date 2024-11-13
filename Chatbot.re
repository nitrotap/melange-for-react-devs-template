[@react.component]
let make = (~message: string, ~onSend: string => unit) => {
  let (prompt, setPrompt) = React.useState(() => "");

  let handleChange = (event: React.Event.Form.t) => {
    let newValue = React.Event.Form.target(event)##value;
    setPrompt(_ => newValue);
  };

  <div>
    <div>{React.string(message)}</div>
    <input
      type_="text"
      value=prompt
      onChange={handleChange}
      placeholder="Enter your prompt"
    />
    <button
      onClick={_ => onSend(prompt)}
    >
      {React.string("Send")}
    </button>
  </div>;
};
