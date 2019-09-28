# Fetch

Fetch libraries and interface for ReasonML/OCaml.

Fetch aims to provide a common interface over different HTTP and Promise-implementations in the ReasonML/OCaml ecosystem.

## [Fetch Core](./src/fetch-core)

Provides a functor for creating and providing your own Fetch-implementation. The goal is to be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

## [Fetch Native Lwt](./src/fetch-native-lwt)

A consumable fetch-library for ReasonML/OCaml native. Uses `Lwt` for its `Promise`-implementation.

## Contributing

Feel free to open an issue and/or grabbing one of the [open issues](https://github.com/lessp/reason-fetch/issues).

## Contributors

All [contributors](https://github.com/lessp/reason-fetch/graphs/contributors) as well as [@ulrikstrid](https://github.com/ulrikstrid) and [@ostera](https://github.com/ostera).
<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://github.com/Et7f3"><img src="https://avatars2.githubusercontent.com/u/29592775?v=4" width="100px;" alt="Et7f3"/><br /><sub><b>Et7f3</b></sub></a><br /><a href="https://github.com/lessp/reason-fetch/commits?author=Et7f3" title="Code">💻</a> <a href="https://github.com/lessp/reason-fetch/issues?q=author%3AEt7f3" title="Bug reports">🐛</a> <a href="#ideas-Et7f3" title="Ideas, Planning, & Feedback">🤔</a> <a href="#maintenance-Et7f3" title="Maintenance">🚧</a> <a href="#review-Et7f3" title="Reviewed Pull Requests">👀</a></td>
    <td align="center"><a href="https://github.com/ulrikstrid"><img src="https://avatars3.githubusercontent.com/u/1607770?v=4" width="100px;" alt="Ulrik Strid"/><br /><sub><b>Ulrik Strid</b></sub></a><br /><a href="https://github.com/lessp/reason-fetch/commits?author=ulrikstrid" title="Code">💻</a> <a href="#ideas-ulrikstrid" title="Ideas, Planning, & Feedback">🤔</a> <a href="#review-ulrikstrid" title="Reviewed Pull Requests">👀</a></td>
  </tr>
</table>

<!-- markdownlint-enable -->
<!-- prettier-ignore-end -->
<!-- ALL-CONTRIBUTORS-LIST:END -->

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details
